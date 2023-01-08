#pragma once

#include <iostream>
#include "database.hpp"
#include <unistd.h>
#include <fstream>
#include <memory>
#include "types.hpp"
#include "database.hpp"
using namespace std;


    class Handler
    {
        public:

            explicit Handler(AbsDataBase<ITEM>* database): database_p(database)
            {

            }

            virtual bool segment_request_frame(const char* request_frame_p, uint16_t size)=0;

            virtual uint16_t build_response_frame(char* resonse_buff, bool is_response_positive)=0;

            virtual bool parse_request_frame()=0;

            bool memory_copy(char* dest, size_t offset_dest, const char* source, size_t offset_source, uint16_t size)
            {
                for(uint16_t i=0; i<size; i++)
                {
                    dest[i + offset_dest] = source[offset_source + i]; 
                }
                return true;
            }

            virtual ~Handler()
            {

            }

        protected:
            AbsDataBase<ITEM>* database_p;  //stack pointer
    };



    //Request frame: Frame_ID (10, 2bytes) + Client_ID (5bytes) + Password(8bytes)
    //Positive Response frame: Frame_ID (50, 2bytes) + Client_ID (5bytes)
    //Negative Response frame: Frame_ID (FF, 2bytes) + Client_ID (5bytes) + ErrorCode (3bytes)
    class HandlerRegister: public Handler
    {
        public:
            explicit HandlerRegister(AbsDataBase<ITEM>* database): Handler(database)
            {
                // initialize buffers
                memset(frame_id_request, '\0', sizeof(frame_id_request));
                memset(password, '\0', sizeof(password));
                memset(client_id, '\0', sizeof(client_id));
                memset(error_code, '\0', sizeof(error_code));
                
            }

            bool segment_request_frame(const char* request_frame_p, uint16_t size) final
            {
                if(size!=15)
                {
                    std::cout<<"Size is wrong."<<std::endl;
                    return false;
                }

                memory_copy(frame_id_request, 0, request_frame_p, 0, 2);

                memory_copy(client_id, 0, request_frame_p, 2, 5);

                memory_copy(password, 0, request_frame_p, 7, 8);

                return true;
            }

            uint16_t build_response_frame(char* resonse_buff, bool is_response_positive) final
            {
                if(is_response_positive)
                {
                    char positive_frame_id_response[2] = {'5', '0'};
                    //memory_copy(frame_id_response, 0, positive_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 0, positive_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    resonse_buff[7] = '\0';
                    return 8;
                }
                else
                {
                    char negative_frame_id_response[2] = {'F', 'F'};
                    memory_copy(resonse_buff, 0, negative_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    memory_copy(resonse_buff, 7, error_code, 0, 3);
                    resonse_buff[10] = '\0';
                    return 11;
                }
            }


            bool parse_request_frame() final
            {
                Client client(client_id, password);
                
                ITEM item(client);
                
                auto res = database_p->find_item(item);

                if(!res.second) // item is not found
                {
                    database_p->insert_item(item);
                    return true;
                }

                memory_copy(error_code, 0, "CRF", 0, 3); // set error code to CRF -> client register failed
                return false;
            }

        private:
            char frame_id_request[2];
            char error_code[3];
            char client_id[5];
            char password[8];            
            
    };


    //Request frame: Frame_ID (11, 2bytes) + Client_ID (5bytes) + Password(8bytes)
    //Positive Response frame: Frame_ID (51, 2bytes) + Client_ID (5bytes)
    //Negative Response frame: Frame_ID (FF, 2bytes) + Client_ID (5bytes) + ErrorCode (3bytes)
    //Error code : Client not found -> CNF, Password is wrong -> PAW
    class HandlerUnregister: public Handler
    {
        public:
            explicit HandlerUnregister(AbsDataBase<ITEM>* database): Handler(database)
            {
                // initialize buffers
                memset(frame_id_request, '\0', sizeof(frame_id_request));
                memset(password, '\0', sizeof(password));
                memset(client_id, '\0', sizeof(client_id));
                memset(error_code, '\0', sizeof(error_code));
                
            }

            bool segment_request_frame(const char* request_frame_p, uint16_t size) final
            {
                if(size!=15)
                {
                    std::cout<<"Size is wrong."<<std::endl;
                    return false;
                }

                memory_copy(frame_id_request, 0, request_frame_p, 0, 2);

                memory_copy(client_id, 0, request_frame_p, 2, 5);

                memory_copy(password, 0, request_frame_p, 7, 8);

                return true;
            }


            uint16_t build_response_frame(char* resonse_buff, bool is_response_positive) final
            {
                if(is_response_positive)
                {
                    char positive_frame_id_response[2] = {'5', '1'};
                    memory_copy(resonse_buff, 0, positive_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    resonse_buff[7] = '\0';
                    return 8;
                }
                else
                {
                    char negative_frame_id_response[2] = {'F', 'F'};
                    memory_copy(resonse_buff, 0, negative_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    memory_copy(resonse_buff, 7, error_code, 0, 3);
                    resonse_buff[10] = '\0';
                    return 11;
                }
            }


            bool parse_request_frame() final
            {
                Client client(client_id, password);
                
                ITEM item(client);
                
                auto res = database_p->find_item(item);

                if(!res.second) // item is not found
                {
                    memory_copy(error_code, 0, "CNF", 0, 3); // set error code to CNF -> client not found
                    return false;
                }
                else
                {
                    bool is_password_identical = res.first.get_client().compare_password(password);
                    if(is_password_identical)
                    {
                        database_p->delete_item(res.first);
                        return true;
                    }
                    else
                    {
                        memory_copy(error_code, 0, "PNI", 0, 3); // set error code to PNI -> password is not identical
                        return false;
                    }
                }
            }

        private:
            char frame_id_request[2];
            char error_code[3];
            char client_id[5];
            char password[8];            
            
    };




    //Request frame: Frame_ID (20, 2bytes) + Client_ID (5bytes) + password(8bytes)
    //Positive Response frame: Frame_ID (60, 2bytes) + Client_ID (5bytes)
    //Negative Response frame: Frame_ID (FF, 2bytes) + Client_ID (5bytes) + ErrorCode (3bytes)
    class HandlerLogin: public Handler
    {
        public:
            explicit HandlerLogin(AbsDataBase<ITEM>* database): Handler(database)
            {
                // initialize buffers
                memset(frame_id_request, '\0', sizeof(frame_id_request));
                memset(password, '\0', sizeof(password));
                memset(client_id, '\0', sizeof(client_id));
                memset(error_code, '\0', sizeof(error_code));                
            }

            bool segment_request_frame(const char* request_frame_p, uint16_t size) final
            {
                if(size!=15)
                {
                    std::cout<<"Size is wrong."<<std::endl;
                    return false;
                }

                memory_copy(frame_id_request, 0, request_frame_p, 0, 2);

                memory_copy(client_id, 0, request_frame_p, 2, 5);

                memory_copy(password, 0, request_frame_p, 7, 8);

                return true;
            }

            uint16_t build_response_frame(char* resonse_buff, bool is_response_positive) final
            {
                if(is_response_positive)
                {
                    char positive_frame_id_response[2] = {'6', '0'};
                    //memory_copy(frame_id_response, 0, positive_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 0, positive_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    resonse_buff[7] = '\0';
                    return 8;
                }
                else
                {
                    char negative_frame_id_response[2] = {'F', 'F'};
                    memory_copy(resonse_buff, 0, negative_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    memory_copy(resonse_buff, 7, error_code, 0, 3);
                    resonse_buff[10] = '\0';
                    return 11;
                }
            }


            bool parse_request_frame() final
            {
                Client client(client_id, password);
                
                ITEM item(client);
                
                auto res = database_p->find_item(item);

                if(!res.second)
                {
                    memory_copy(error_code, 0, "CNF", 0, 3); // set error code to CNF -> client not found
                    return false;
                }

                bool is_password_identical = res.first.get_client().compare_password(password);

                if(!is_password_identical)
                {
                    memory_copy(error_code, 0, "PNI", 0, 3); // set error code to PNI -> password is not identical
                    return false;
                }

                bool is_client_already_login = res.first.get_client().get_login_status();

                if(is_client_already_login)
                {
                    memory_copy(error_code, 0, "LIR", 0, 3); // set error code to LIF -> Login failed
                    return false;
                }

                res.first.modify_login_status(true); // change the status of client from item

                database_p->update_database(res.first);

                return true;
            }

        private:
            char frame_id_request[2];
            char error_code[3];
            char client_id[5];
            char password[8];            
            
    };



    //Request frame: Frame_ID (21, 2bytes) + Client_ID (5bytes) + password(8bytes)
    //Positive Response frame: Frame_ID (61, 2bytes) + Client_ID (5bytes)
    //Negative Response frame: Frame_ID (FF, 2bytes) + Client_ID (5bytes) + ErrorCode (3bytes)
    class HandlerLogout: public Handler
    {
        public:
            explicit HandlerLogout(AbsDataBase<ITEM>* database): Handler(database)
            {
                // initialize buffers
                memset(frame_id_request, '\0', sizeof(frame_id_request));
                memset(password, '\0', sizeof(password));
                memset(client_id, '\0', sizeof(client_id));
                memset(error_code, '\0', sizeof(error_code));                
            }

            bool segment_request_frame(const char* request_frame_p, uint16_t size) final
            {
                if(size!=15)
                {
                    std::cout<<"Size is wrong."<<std::endl;
                    return false;
                }

                memory_copy(frame_id_request, 0, request_frame_p, 0, 2);

                memory_copy(client_id, 0, request_frame_p, 2, 5);

                memory_copy(password, 0, request_frame_p, 7, 8);

                return true;
            }

            uint16_t build_response_frame(char* resonse_buff, bool is_response_positive) final
            {
                if(is_response_positive)
                {
                    char positive_frame_id_response[2] = {'6', '1'};
                    //memory_copy(frame_id_response, 0, positive_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 0, positive_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    resonse_buff[7] = '\0';
                    return 8;
                }
                else
                {
                    char negative_frame_id_response[2] = {'F', 'F'};
                    memory_copy(resonse_buff, 0, negative_frame_id_response, 0, 2);
                    memory_copy(resonse_buff, 2, client_id, 0, 5);
                    memory_copy(resonse_buff, 7, error_code, 0, 3);
                    resonse_buff[10] = '\0';
                    return 11;
                }
            }


            bool parse_request_frame() final
            {
                Client client(client_id, password);
                
                ITEM item(client);
                
                auto res = database_p->find_item(item);

                if(!res.second) // client is not found
                {
                    memory_copy(error_code, 0, "CNF", 0, 3); // set error code to CNF -> client not found
                    return false;
                }

                bool is_password_identical = res.first.get_client().compare_password(password);

                if(!is_password_identical) // password not identical
                {
                    memory_copy(error_code, 0, "PNI", 0, 3); // set error code to PNI -> password is not identical
                    return false;
                }

                if(res.first.get_client().get_login_status())
                {
                    res.first.modify_login_status(false); // change login status to false
                    database_p->update_database(res.first);
                    return true;
                }
                else
                {
                    memory_copy(error_code, 0, "LOR", 0, 3); // set error code to LOR -> Logout repeat
                    return false;
                }
            }

        private:
            char frame_id_request[2];
            char error_code[3];
            char client_id[5];
            char password[8];            
            
    };


























    class HandlerFactory
    {
        public:
            explicit HandlerFactory(char* buff): buff(buff)
            {

            }

            //Create handler instance due to Frame_ID
            std::shared_ptr<Handler> create_handler(AbsDataBase<ITEM>* database)
            {
                //Handle kinds of command from client
                if(buff[0] == '1' && buff[1] == '0') // register handler
                {
                    std::cout<<"Register Request!"<<std::endl;
                    handler_p = std::make_shared<HandlerRegister>(database);
                    return handler_p;
                }
                else if(buff[0] == '1' && buff[1] == '1') // unregister handler
                {
                    std::cout<<"Unregister Request!"<<std::endl;
                    handler_p = std::make_shared<HandlerUnregister>(database);
                    return handler_p;
                }
                else if(buff[0] == '2' && buff[1] == '0') // login handler
                {
                    std::cout<<"Login Request!"<<std::endl;
                    handler_p = std::make_shared<HandlerLogin>(database);
                    return handler_p;
                }
                else if(buff[0] == '2' && buff[1] == '1') // logout handler
                {
                    std::cout<<"Logout Request!"<<std::endl;
                    handler_p = std::make_shared<HandlerLogout>(database);
                    return handler_p;
                }
                else
                {
                    return nullptr;
                }
            }

            ~HandlerFactory()
            {
                //delete register_handler_p;
            }

        private:
            char* buff;
            std::shared_ptr<Handler> handler_p{nullptr};

    };




