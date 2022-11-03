#pragma once

#include <iostream>
#include "sqlite3ext.h"
#include "sqlite3.h"



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

};



//Request frame: Frame_ID (10, 2bytes) + User_Name (10bytes) + Password(7bytes)
//Response frame: Frame_ID (3bytes) + Client_ID (5bytes)
class HandlerRegister: public Handler
{
public:

    HandlerRegister() = default;

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

        return 10;        
    }

    void modify_database() final
    {
        
    }

private:
    
    //Database* data_base;
    char frame_id_request[2];
    char user_name[10];
    char password[7];
    char frame_id_response[3];
    char client_id[5];

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
    Handler* create_handler()
    {
        if(buff[0] == '1' && buff[1] == '0') // register handler
        {
            auto p = new HandlerRegister();
            return p;
        }
    }

private:
    char* buff;

};





