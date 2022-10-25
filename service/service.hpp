#pragma once

#include "hotel.hpp"
#include "protocal.hpp"


class Service
{
public:
    virtual void supply_service()=0;
    virtual void build_response_frame()=0;


protected:
    Hotel *hotel;
    char* request_buf_p;
    char response_buf[128]; 
};


//Request frame: Frame_ID + Client_ID + Booking_ID
//Response frame: Frame_ID + Client_ID + Cancel_Booking_Status
class ServiceCancelBookingRegistered: public Service
{
public:
    virtual void supply_service()
    {

    }

    virtual void build_response_frame()
    {

    }
};


class ServiceCancelBookingUnregistered: public Service
{
public:
    virtual void supply_service()
    {
        
    }

    virtual void build_response_frame()
    {
        
    }


};


class ServiceBookingRegistered: public Service
{
public:
    virtual void supply_service()
    {
        
    }


    virtual void build_response_frame()
    {
        
    }

};


class ServiceBookingUnregistered: public Service
{
public:
    virtual void supply_service()
    {
        
    }


    virtual void build_response_frame()
    {
        
    }

};



class ServiceRegister: public Service
{
public:
    virtual void supply_service()
    {
        
    }


    virtual void build_response_frame()
    {
        
    }

};



class ServiceModificationPassword: public Service
{
public:
    virtual void supply_service()
    {
        
    }

    virtual void build_response_frame()
    {
        
    }

};


class ServiceDeleteAccount: public Service
{

public:
    virtual void supply_service()
    {
        
    }


    virtual void build_response_frame()
    {
        
    }

};


class ServiceUpdate: public Service
{

public:
    virtual void supply_service()
    {
        
    }


    virtual void build_response_frame()
    {
        
    }

};


class ServiceLogin: public Service
{

public:
    virtual void supply_service()
    {
        
    }


    virtual void build_response_frame()
    {
        
    }

};


class ServiceLogout: public Service
{

public:
    virtual void supply_service()
    {
        
    }


    virtual void build_response_frame()
    {
        
    }

};



































