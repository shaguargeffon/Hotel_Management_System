#include "com.hpp"
#include <iostream>
#include "database.hpp"



using namespace std;

COM::COM(int port, unsigned int amount_clients): server_port(port), max_clients(amount_clients)
{
}

void COM::create_socket() 
{
    sfd = socket(AF_INET, SOCK_STREAM, 0); //create server socket
}

void COM::set_ip_format()
{
    serv_addr.sin_family = AF_INET; //IPV4 is used
}

void COM::set_server_port()
{
    serv_addr.sin_port = htons(server_port); //bind the port
}

void COM::configure_valid_ip_address()
{
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //listen to all IP address
}

void COM::bind_server() 
{
    bind(sfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
}

void COM::listen_clients()
{
    listen(sfd, max_clients);  //max_clients means how many clients are allowed to connet to the server at the same time
}

void COM::accpet_clients()
{
    clie_len = sizeof(clie_addr);
    cfd = accept(sfd, (struct sockaddr*)&clie_addr, &clie_len); //blocking mode
}

void COM::close_server()
{
    close(sfd);
}

void COM::close_client()
{
    close(cfd);
}


void COM::start_server()
{
    DataBase<ITEM> data_base;

    ServiceFactory service_factory(rec_buf);

    while(1)
    {
        unsigned int receive_size = read(cfd, rec_buf, sizeof(rec_buf));

        if(receive_size == 0) // nothing read from client
        {
            std::cout<<"nothing read from client!"<<std::endl;
            continue;
        }

        auto service = service_factory.create_service(&data_base);

        service->segment_request_frame(rec_buf, receive_size);

        bool is_request_frame_positive = service->parse_request_frame();

        unsigned int send_buf_size = service->build_response_frame(send_buf, is_request_frame_positive);

        write(cfd, send_buf, send_buf_size);
    }
}
