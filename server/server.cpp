#include "server.hpp"
#include <iostream>
#include "database.hpp"



using namespace std;

TcpServer::TcpServer(int port, unsigned int amount_clients): server_port(port), max_clients(amount_clients)
{
}

void TcpServer::create_socket() 
{
    sfd = socket(AF_INET, SOCK_STREAM, 0); //create server socket
}

void TcpServer::set_ip_format()
{
    serv_addr.sin_family = AF_INET; //IPV4 is used
}

void TcpServer::set_server_port()
{
    serv_addr.sin_port = htons(server_port); //bind the port
}

void TcpServer::configure_valid_ip_address()
{
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //listen to all IP address
}

void TcpServer::bind_server() 
{
    bind(sfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
}

void TcpServer::listen_clients()
{
    listen(sfd, max_clients);  //max_clients means how many clients are allowed to connet to the server at the same time
}

void TcpServer::accpet_clients()
{
    clie_len = sizeof(clie_addr);
    cfd = accept(sfd, (struct sockaddr*)&clie_addr, &clie_len); //blocking mode
}

void TcpServer::close_server()
{
    close(sfd);
}

void TcpServer::close_client()
{
    close(cfd);
}


void TcpServer::start_server()
{
    DataBase<ITEM> data_base;

    HandlerFactory handler_factory(rec_buf);

    while(1)
    {
        unsigned int receive_size = read(cfd, rec_buf, sizeof(rec_buf));

        if(receive_size == 0) // nothing read from client
        {
            std::cout<<"nothing read from client!"<<std::endl;
            continue;
        }

        auto handler = handler_factory.create_handler(&data_base);

        handler->segment_request_frame(rec_buf, receive_size);

        bool is_request_frame_positive = handler->parse_request_frame();

        unsigned int send_buf_size = handler->build_response_frame(send_buf, is_request_frame_positive);

        write(cfd, send_buf, send_buf_size);
    }
}
