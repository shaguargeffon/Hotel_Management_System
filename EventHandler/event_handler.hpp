#pragma once

//#include <array>
#include <iostream>
#include <string>
//#include <algorithm>
#include <cstdint>
#include <cstring>
#include <vector>
#include <memory>
#include <optional>
#include "event.hpp"


template<typename COM_T>
class EventHandler {
public:
    EventHandler(COM_T& com): com_(com) {

    }

    //blocking mechanism
    void update_event() {
        auto size = com_.receive_data(); //com_ receive buffer is updated, block function
        //Event event{(com_.get_recv_buffer())[0], com_.get_recv_buffer(), size}; //create an event
        __write_event(Event{(com_.get_recv_buffer())[0], com_.get_recv_buffer(), size});
    }

    std::optional<Event> read_event() {
        if (!event_buffer_.empty()) {
            Event event{event_buffer_.front()};
            static_cast<void>(event_buffer_.erase(event_buffer_.begin()));
            return std::make_optional<Event>(event);
        }
        
        return {};
    }

private:
    void __write_event(Event&& event) {
        event_buffer_.push_back(event);
    }

private:
    COM_T& com_;
    std::vector<Event> event_buffer_;
};











