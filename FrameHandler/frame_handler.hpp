#pragma once

#include <tuple>
#include <any>
#include <typeinfo>
#include "frame.hpp"
#include "event_handler.hpp"

template<typename FrameTuple_t, typename EventHandler_t>
class FrameHandler {
public:

    FrameHandler(FrameTuple_t& frame_tuple, EventHandler_t& event_handler): frame_tuple_(frame_tuple), event_handler_(event_handler) {

    }

    void handle_frame() {
        auto event = Event{2, test_dataset, 18};
        
        std::apply(
            [&event](auto&&... arg){
                ((arg.parse_event(&event)), ...);
            },
            frame_tuple_
        );
    }

private:
    FrameTuple_t& frame_tuple_;
    EventHandler_t& event_handler_;
    char test_dataset[18]{2, 'H', 'a', 'n', 'D', 'i', '\0', '\0', '\0', '\0', '\0', '1', 23, 12, 1, 23, 12, 5}; //only for test
};










