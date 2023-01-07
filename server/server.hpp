#pragma once

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

#include "handler.hpp"


class Server
{
public:
    virtual void initialize_server()=0;
    virtual void start()=0;
    virtual void stop_server()=0;
    virtual void stop_client()=0;
};


class TcpServer: public Server
{
public:
    TcpServer(int port=1111, unsigned int amount_clients=10);

private:
    void create_socket(); 

    void set_ip_format();

    void set_server_port();

    void configure_valid_ip_address();

    void bind_server();

    void listen_clients();

    void accpet_clients();

    void close_server();

    void close_client();

    void start_server();

    unsigned int receive_message();

    void send_message(unsigned int send_size);

    Handler* handler_factory();

public:
    void initialize_server() final
    {
        create_socket();
        set_ip_format();
        set_server_port();
        configure_valid_ip_address();
        bind_server();
        listen_clients();
        accpet_clients(); 
    }


    void start() final
    {
        start_server();
    }

    void stop_server() final
    {
        close_server();
    }

    void stop_client() final
    {
        close_client();
    }


private:
    int sfd{0};   //server socket file descriptor
    int cfd{0};   //client socket file descriptor
    int server_port; // server port
    struct sockaddr_in serv_addr;  //struct of server address
    struct sockaddr_in clie_addr;  //struct of client address
    socklen_t clie_len{0}; //size of client struct
    unsigned int max_clients; // maximal clients connected at the same time
    char rec_buf[BUFSIZ];
    char send_buf[BUFSIZ];
    char frame_id[2];

    //Handler* handler;

};


