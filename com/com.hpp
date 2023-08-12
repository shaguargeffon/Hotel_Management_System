#pragma once

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

class COM {
public:
    COM(int port): server_port(port) {
    }

    void create_socket() {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (server_fd < 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }
    }
    

    void attach_port_to_socket() {
        int opt = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
    }


    void configure_address() {
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(server_port);
    }


    void bind_address() {
        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
    }

    void listen_clients() {
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
    }

    void accept_clients() {
        int addrlen = sizeof(address);
        socket_instance = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        
        if (socket_instance < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
    }

    void send_data(unsigned int send_size) {
        send(socket_instance, send_buf, send_size, 0);
    }


    int receive_data() {
        int mysize = read(socket_instance, recv_buf, sizeof(recv_buf));
        return mysize;
    }


    void close_socket() {
        close(socket_instance);
    }


    void shutdown_socket() {
        shutdown(server_fd, SHUT_RDWR);
    }

    void fill_send_buffer(char* data, int data_size) {
        std::memcpy(send_buf, data, data_size);
    }


    void print_receive_data(int receive_size) {
        for(int i=0; i<receive_size; i++) {
            std::cout<<recv_buf[i];
        }
    }

    char* get_recv_buffer() {
        return recv_buf;
    }


private:
    int server_fd{0};   //server socket file descriptor
    int client_fd{0};   //client socket file descriptor
    int server_port; // server port
    int socket_instance;
    struct sockaddr_in address;
    char recv_buf[BUFSIZ];
    char send_buf[BUFSIZ];
};

