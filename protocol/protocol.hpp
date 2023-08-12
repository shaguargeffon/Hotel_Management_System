#pragma once

template<typename COM_T>
struct ProtocolIDFunctor {
auto operator()(COM_T& com){
    auto recv_buffer_p = com.get_recv_buffer();
    return *recv_buffer_p; // the first byte (Frame ID) is also used as protocol ID
}
};



struct ProtocolMappingFunctor{


void operator()(auto protocol_id){


}



};










