#pragma once

//#include <array>
#include <iostream>
#include <string>
//#include <algorithm>
#include <cstdint>
#include <cstring>
#include <queue>
#include <memory>
#include <optional>
#include <tuple>
#include <functional>
#include "event.hpp"


template <
    size_t Index = 0, // start iteration at 0 index
    typename TTuple,  // the tuple type
    size_t Size =
        std::tuple_size_v<
            std::remove_reference_t<TTuple>>, // tuple size
    typename TCallable, // the callable to be invoked for each tuple item
    typename... TArgs   // other arguments to be passed to the callable 
>
void for_each(TTuple&& tuple, TCallable&& callable, TArgs&&... args)
{
    if constexpr (Index < Size)
    {
        std::invoke(callable, args..., std::get<Index>(tuple));

        if constexpr (Index + 1 < Size)
            for_each<Index + 1>(
                std::forward<TTuple>(tuple),
                std::forward<TCallable>(callable),
                std::forward<TArgs>(args)...);
    }
}


template<typename COM_T>
class EventHandler {
public:
    EventHandler(COM_T& com): com_(com) {

    }

    //blocking mechanism
    void update_event() {
        auto size = com_.receive_data(); //com_ receive buffer is updated, block function

        event_buffer_.emplace(com_.get_recv_buffer()[0], com_.get_recv_buffer(), size);
    }

    template<typename ...Frames>
    bool consume_event(std::tuple<Frames...>& frames) {
        if(event_buffer_.empty) {
            return false;
        }
        
        int consume_cnt{0};
        
        for_each(frames, [this, &consume_cnt](const auto& frame) {
            if( (frame.get_instance()).parse_event(&event_buffer_.front()) == true) {
                consume_cnt++;
            }
        });

        event_buffer_.pop();

        if(consume_cnt == 0) {
            return false;
        }

        return true;
    }


private:
    COM_T& com_;
    std::queue<Event> event_buffer_;
};











