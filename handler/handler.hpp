#pragma once

#include <iostream>
#include "database.hpp"
#include <unistd.h>
#include <fstream>
#include <memory>
using namespace std;



class Handler
{
public:
    virtual bool parse_request_frame(const char* request_frame_p, unsigned int size)=0;

    virtual unsigned int build_response_frame(char* resonse_buff)=0;

    virtual void modify_database()=0;

    bool memory_copy(char* dest, unsigned int offset_dest, const char* source, unsigned int offset_source, unsigned int size)
    {
        for(unsigned int i=0; i<size; i++)
        {
            dest[i + offset_dest] = source[offset_source + i]; 
        }
        return true;
    }

    virtual ~Handler()
    {

    }
};



//Request frame: Frame_ID (10, 2bytes) + User_Name (10bytes) + Password(7bytes)
//Response frame: Frame_ID (3bytes) + Client_ID (5bytes)
class HandlerRegister: public Handler
{
public:

    HandlerRegister()
    {
        customer_db_p = std::make_shared<CustomerDataBase>("database.db");
    }

    bool parse_request_frame(const char* request_frame_p, unsigned int size) final
    {
        if(size!=19)
        {
            return false;
        }

        memory_copy(frame_id_request, 0, request_frame_p, 0, 2);

        memory_copy(user_name, 0, request_frame_p, 2, 10);

        memory_copy(password, 0, request_frame_p, 12, 7);

        return true;
    }

    //TBD: implemente checking user name from data base.
    bool is_user_name_registered(char* name)
    {
        return false;
    }

    unsigned int build_response_frame(char* resonse_buff) final
    {
        if(is_user_name_registered(user_name))
        {
            std::cout<<"the user is already registered"<<std::endl;
            return 0;
        }

        memory_copy(frame_id_response, 0, frame_id_request, 0, 2);
        memory_copy(frame_id_response, 2, "1", 0, 1); // '1': OK, '0': not OK

        memory_copy(client_id, 0, "abcde", 0, 5); // TBD: generate a random client ID

        //copy the frames into response buffer
        memory_copy(resonse_buff, 0, frame_id_response, 0, 3);
        memory_copy(resonse_buff, 3, client_id, 0, 5);

        resonse_buff[9] = '\0';
        //std::cout<<"it runs."<<std::endl;
        this->modify_database();

        return 10;        
    }

    void modify_database() final
    {
        
        //string database_path("database.db");
        //CustomerDataBase my_database(database_path);

        ifstream bfile(database_path.c_str());

        bfile.open("database.db");

        if(bfile) //file exists
        {
            cout<<"SQL file already exists."<<endl;
        }
        else
        {
            cout<<"SQL file doesn't exist."<<endl;

            int result = customer_db_p->open_database();

            if(result != SQLITE_OK)
            {
                cout<<"File creation is failed."<<endl;
            }
            else
            {
                const char* table = "create table hunter(ClientID integer primary key autoincrement, name string, age integer, sex string)";
                result = customer_db_p->create_table(table);

                if(result != SQLITE_OK)
                {
                    cout<<"SQL table is created unsuccessfully."<<endl;
                }
                else
                {
                    cout<<"SQL table is created successfully."<<endl;
                }

            }
        }

        //db->open_database();
        //db->create_table();
        customer_db_p->close_database();
    }


private:
    
    //Database* data_base;
    char frame_id_request[2];
    char user_name[10];
    char password[7];
    char frame_id_response[3];
    char client_id[5];
    string database_path{"database.db"};
    std::shared_ptr<CustomerDataBase> customer_db_p;
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
    HandlerFactory(char* buff): buff(buff)
    {

    }

    //Create handler instance due to Frame_ID
    std::shared_ptr<Handler> create_handler()
    {
        if(buff[0] == '1' && buff[1] == '0') // register handler
        {
            if(register_handler_p == nullptr) // to ensure that only one HanlderRegister is allocated.
            {
                register_handler_p = std::make_shared<HandlerRegister>(); ;
            }

            return register_handler_p;
        }
    }


    ~HandlerFactory()
    {
        //delete register_handler_p;
    }

private:
    char* buff;
    std::shared_ptr<Handler> register_handler_p{nullptr};


};





