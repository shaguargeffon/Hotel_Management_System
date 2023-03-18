//#include <pthread.h>
//#include <stdio.h>
//#include <ctype.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <stdlib.h>
#include "com.hpp"
#include "handler.hpp"



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
    
    COM com(9527, 32);


    com.initialize_server();


    com.start();


    com.stop_server();


    com.stop_client();



   cout<<"Software is running!"<<endl;


    return 0;
}



