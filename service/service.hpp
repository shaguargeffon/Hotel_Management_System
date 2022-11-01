#pragma once

#include "server.hpp"
#include "protocal.hpp"

class Service
{
public:

    virtual void init_communication()
    {
         tcp_server_p->create_socket();

         tcp_server_p->set_ip_format();

         tcp_server_p->set_server_port();

         tcp_server_p->configure_valid_ip_address();

         tcp_server_p->bind_server();

         tcp_server_p->listen_clients();

         tcp_server_p->accpet_clients();
    }


    virtual void close_communication()
    {
        tcp_server_p->close_server();

        tcp_server_p->close_client();
    }

    virtual void supply_service() = 0;


protected:
    TcpServer* tcp_server_p;
    Protocal* my_protocal;
};


class ServiceRegister: public Service
{
public:

    ServiceRegister(TcpServer* tcp_server) 
    {
        tcp_server_p = tcp_server;
        my_protocal =  new ProtocalRegister(tcp_server_p->get_receive_buff_pointer());
    }


    void supply_service() final
    {
        unsigned int rec_size = tcp_server_p->receive_message();

        my_protocal->parse_request_frame();
        
        unsigned int send_buff_size = my_protocal->build_response_frame(tcp_server_p->get_send_buff_pointer());

        tcp_server_p->send_message(send_buff_size);

    }

};
























