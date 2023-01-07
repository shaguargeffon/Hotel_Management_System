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
    //Negative Response frame: Frame_ID (FF, 2bytes) + Client_ID (5bytes) + ErrorCode (2bytes)
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
                    memory_copy(resonse_buff, 7, error_code, 0, 2);
                    resonse_buff[9] = '\0';
                    return 10;
                }
            }


            bool parse_request_frame() final
            {
                Client client(client_id);
                
                ITEM item(client);
                
                bool is_item_found = database_p->find_item(item);

                if(!is_item_found)
                {
                    memory_copy(error_code, 0, "NF", 0, 2); // set error code to NF -> not found
                    database_p->insert_item(item);
                    return true;
                }

                return false;
            }

        private:
            char frame_id_request[2];
            char error_code[2];
            char client_id[5];
            char password[8];            
            
    };


/*
class ProtocalCancelBookingRegistered: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {

    }


private:
    char* request_frame_p;
};


class ProtocalCancelBookingUnregistered: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
    
};


class ProtocalBookingRegistered: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
};


class ProtocalBookingUnregistered: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
};









class ProtocalModificationPassword: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
};


class ProtocalDeleteAccount: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
};


class ProtocalUpdate: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
};


class ProtocalLogin: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
};


class ProtocalLogout: public Protocal
{
public:
    virtual bool parse_request_frame()
    {

    }

    virtual bool build_response_frame()
    {

    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
};



*/



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
                    if(handler_p == nullptr) // to ensure that only one HanlderRegister is allocated.
                    {
                        handler_p = std::make_shared<HandlerRegister>(database);
                    }

                    return handler_p;
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




