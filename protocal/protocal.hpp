#pragma once
/*

class Protocal
{
public:
    virtual bool parse_request_frame()=0;

    virtual bool build_response_frame()=0;

    virtual void modify_database()=0;

    bool memory_copy(char* dest, int offset_dest, char* source, int offset_source, int size)
    {
        for(int i=0; i<size; i++)
        {
            dest[offset_dest] = source[offset_source + i]; 
        }
        return true;
    }

};



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




//Request frame: Frame_ID (2bytes) + Name (10bytes) + Password(7bytes)
//Response frame: Frame_ID (3bytes) + Client_ID (5bytes) + Register_Status (1byte)
class ProtocalRegister: public Protocal
{
public:
    virtual bool parse_request_frame()
    {
        memory_copy(frame_id_request, 0, request_frame_p, 0, 2);

        memory_copy(user_name, 0, request_frame_p, 2, 10);

        memory_copy(password, 0, request_frame_p, 12, 7);

        return true;
    }

    //TBD: implemente checking user name from data base.
    bool is_user_name_registered(char* name)
    {
        return true;
    }

    virtual bool build_response_frame()
    {
        if(is_user_name_registered(user_name))
        {
            return false;
        }

        frame_id_response[0] = '1';

        memory_copy(frame_id_response, 1, frame_id_request, 0, 2);

        memory_copy(client_id, 0, "abcde", 0, 5); // TBD: generate a random client ID


        memory_copy(register_status, 0, "1", 0, 1);


        //copy the frames into response buffer
        memory_copy(resonse_buff, 0, frame_id_response, 0, 3);
        memory_copy(resonse_buff, 3, client_id, 0, 5);
        memory_copy(resonse_buff, 8, register_status, 0, 1);

        resonse_buff[9] = '\0';

        return true;        
    }

    virtual void modify_database()
    {
        
    }

private:
    char* request_frame_p;
    //Database* data_base;
    char frame_id_request[2];
    char user_name[10];
    char password[7];
    char frame_id_response[3];
    char client_id[5];
    char register_status[1];
    char resonse_buff[10];
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
