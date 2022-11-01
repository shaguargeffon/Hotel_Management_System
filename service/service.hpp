#pragma once

#include "server.hpp"
#include "protocal.hpp"

class Service
{

public:
    virtual void supply_service() = 0;


protected:
    TcpServer* tcp_server_p;
    Protocal* protocal;
}:


class ServiceRegister
{
public:
    ServiceRegister(TcpServer* tcp_server): tcp_server_p(tcp_server)
    {
    }

    void supply_service() final
    {
        unsigned int rec_size = tcp_server_p->receive_message();

        ProtocalRegister my_protocal(tcp_server_p->get_receive_buff_pointer());

        my_protocal.parse_request_frame();
        
        unsigned int send_buff_size = my_protocal.build_response_frame(tcp_server_p->get_send_buff_pointer());

        tcp_server_p->send_message(send_buff_size);

    }

private:
    int a;

}
























