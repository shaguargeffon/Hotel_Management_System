#include "server.hpp"


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
    while(1)
    {
        int n = read(cfd, buf, sizeof(buf));
        
        for(int i = 0; i < n; i++)
        {   
            buf[i] = toupper(buf[i]); //read data from client
        }

	    write(cfd, buf, n);
    }
}

