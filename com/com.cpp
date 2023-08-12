#include "com.hpp"


using namespace std;


/*
void Com::start_server()
{
    //DataBase<ITEM> data_base;

    //ServiceFactory service_factory(rec_buf);

    while(1)
    {

        unsigned int receive_size = read(cfd, rec_buf, sizeof(rec_buf));

        if(receive_size == 0) // nothing read from client
        {
            //std::cout<<"nothing read from client!"<<std::endl;
            continue;
        }

        //auto service = service_factory.create_service(&data_base);

        //service->segment_request_frame(rec_buf, receive_size);

        //bool is_request_frame_positive = service->parse_request_frame();

        //unsigned int send_buf_size = service->build_response_frame(send_buf, is_request_frame_positive);




        write(cfd, send_buf, send_buf_size);
    }
}

*/
