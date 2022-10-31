//#include <pthread.h>
//#include <stdio.h>
//#include <ctype.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <stdlib.h>
#include "server/server.hpp"
//#include "protocal.hpp"
//#include "hotel.hpp"
//#include "service.hpp"


//compiling command: gcc -pthread -g -o main main.c


#define SERV_PORT 9527


/*
void* thread_1(void *arg)
{
    //cout<<"This is thread 1"<<endl;
    pthread_exit(NULL);
}


void* thread_2(void *arg)
{
    //cout<<"This is thread 2"<<endl;
    pthread_exit(NULL);
}
*/



int main()
{
    TcpServer tcp_server(9527, 32);

    tcp_server.create_socket();

    tcp_server.set_ip_format();

    tcp_server.set_server_port();

    tcp_server.configure_valid_ip_address();

    tcp_server.bind_server();

    tcp_server.listen_clients();

    tcp_server.accpet_clients();

    tcp_server.start_server();

    tcp_server.close_server();

    tcp_server.close_client();

    return 0;
}



