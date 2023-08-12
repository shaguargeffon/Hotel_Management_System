//#include <pthread.h>
#include <stdio.h>
//#include <ctype.h>
#include <unistd.h>
//#include <sys/types.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
#include <stdlib.h>
#include <string>
#include <cstring>
//#include "com.hpp"
//#include "service.hpp"
//#include "execution_manager"


//compiling command: gcc -pthread -g -o main main.c

#include "com.hpp"
#include "frame_handler.hpp"
#include "frame.hpp"
//#include "tuple_api.hpp"
#include "event_handler.hpp"




int main()
{
    /*
    COM com{8080};

    com.create_socket();
    com.attach_port_to_socket();
    com.configure_address();
    com.bind_address();
    com.listen_clients();
    com.accept_clients();
    
    while(1) {
        com.send_data(5);
        printf("Data sent\n");
        usleep(1000000);
        int receive_size = com.receive_data();
        printf("Data received\n");
        com.print_receive_data(receive_size);
        
        usleep(1000000);
    }

    com.close_socket();

    com.shutdown_socket();
    */

    //static std::tuple<> mydata;

    //using FH = RequestFrameSet<FrameRequestRegisterNewAccount, FrameRequestBookHotel, FrameRequestCancelBooking>;

    std::tuple<FrameRequestRegisterNewAccount, FrameRequestBookHotel, FrameRequestCancelBooking> request_frames{
        FrameRequestRegisterNewAccount::create_instance(),
        FrameRequestBookHotel::create_instance(),
        FrameRequestCancelBooking::create_instance()
    };

    char test_dataset[18] = {2, 'H', 'a', 'n', 'D', 'i', '\0', '\0', '\0', '\0', '\0', '1', 23, 12, 1, 23, 12, 5};
    Event test_event{2, test_dataset, 18};

    // loop over the tuple
    std::apply(
        [&test_event](auto&&... arg){
            ((arg.parse_event(&test_event)), ...);
        },
        request_frames
    );


    return 0;
}



