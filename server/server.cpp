#include "server.hpp"
#include <iostream>



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
    /*
    int n = read(cfd, buf, sizeof(buf));
        
    for(int i = 0; i < n; i++)
    {   
        buf[i] = toupper(buf[i]); //read data from client
    }

    write(cfd, buf, n);
    */

    while(1)
    {
        unsigned int receive_size = read(cfd, rec_buf, sizeof(rec_buf));

        HandlerFactory handler_factory(rec_buf);

        Handler* handler = handler_factory.create_handler();

        handler->parse_request_frame(rec_buf, receive_size);

        unsigned int send_buf_size = handler->build_response_frame(send_buf);

        for(unsigned int i=0; i<send_buf_size;i++)
        {
            std::cout<<send_buf[i]<<std::endl;
        }

        write(cfd, send_buf, send_buf_size);

    }


}


unsigned int TcpServer::receive_message()
{
    unsigned int rec_size = read(cfd, rec_buf, sizeof(rec_buf));

    std::cout<<"Receive Buffer is :"<<std::endl;
    
    for(unsigned int i=0; i<rec_size;i++)
    {
        std::cout<<rec_buf[i]<<std::endl;
    }

    return rec_size;
}


void TcpServer::send_message(unsigned int send_size)
{
    std::cout<<"Send Buffer is :"<<std::endl;
    for(unsigned int i=0; i<send_size;i++)
    {
        std::cout<<send_buf[i]<<std::endl;
    }

    write(cfd, send_buf, send_size);
}



