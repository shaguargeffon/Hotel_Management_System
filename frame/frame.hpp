#pragma once

#include <array>
#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include "config.hpp"
#include "event.hpp"


template<typename Frame, typename Event>
static bool copy_from_event_to_frame(Frame& frame_container, Event& event_container, size_t start_index, size_t end_index) {
        for(size_t i=start_index; i<end_index; i++) {
            frame_container[i] = event_container[i];
        }
    }


// Protocol : event/frame ID (1byte), user name (10 bytes), password (10 bytes), email(20 bytes) 
class FrameRequestRegisterNewAccount {
public:
    static FrameRequestRegisterNewAccount& create_instance() {
        static FrameRequestRegisterNewAccount instance;
        return instance;
    }

    const char id{1};
    static constexpr const size_t frame_size{41};

    bool parse_event(Event* event_p) {
        
        if(event_p->get_event_id() == id) {
            event_p_ = event_p;
        }
        else {
            event_p_ = nullptr;
            return false;
        }
        
        if (event_p_->get_event_size() != frame_size) {
            return false; // TBD: add error handling
        }
        
        const auto& data = event_p_->get_event_data();
        
        for(auto &ele : frame_index_config[id]){
            copy_from_event_to_frame(user_name_, data, std::get<0>(ele), std::get<1>(ele));
        }

        //copy_from_event_to_frame(user_name_, data, 1, 11);
        //copy_from_event_to_frame(password_, data, 11, 21);
        //copy_from_event_to_frame(email_, data, 21, 41);
        
        return true;
    } 


    void print() {
        std::cout<<"print called"<<std::endl;
    }

private:
    Event* event_p_{nullptr};
    std::array<char, 10> user_name_{};
    std::array<char, 10> password_{};
    std::array<char, 20> email_{};
};



// Protocol : event/frame ID (1byte), user_name_(10 bytes), room_id_(1byte), year_start_(1byte), month_start_(1byte), day_start_(1byte)
//            year_end_(1byte), month_end_(1byte), day_end_(1byte)
class FrameRequestBookHotel {
public:
    static FrameRequestBookHotel& create_instance() {
        static FrameRequestBookHotel instance;
        return instance;
    }

    const char id{2};

    static constexpr size_t frame_size{18};

    bool parse_event(Event* event_p) {
        
        if(event_p->get_event_id() == id) {
            event_p_ = event_p;
        }
        else {
            event_p_ = nullptr;
            return false;
        }

        if (event_p_->get_event_size() != frame_size) {
            return false; // TBD: add error handling
        }
        
        const auto& data = event_p_->get_event_data();
        
        for(auto &ele : frame_index_config[id]){
            copy_from_event_to_frame(user_name_, data, std::get<0>(ele), std::get<1>(ele));
        }
        
        /*
        copy_from_event_to_frame(user_name_, data, 1, 11);
        copy_from_event_to_frame(room_id_, data, 11, 12);
        copy_from_event_to_frame(year_start_, data, 12, 13);
        copy_from_event_to_frame(month_start_, data, 13, 14);
        copy_from_event_to_frame(day_start_, data, 14, 15);
        copy_from_event_to_frame(year_end_, data, 15, 16);
        copy_from_event_to_frame(month_end_, data, 16, 17);
        copy_from_event_to_frame(day_end_, data, 17, 18);
        */

        return true;
    } 

    void print() {
        std::cout<<"print called"<<std::endl;
    }


private:
    Event* event_p_{nullptr};
    std::array<char, 10> user_name_{};
    std::array<char, 1> room_id_{};
    std::array<char, 1> year_start_{};
    std::array<char, 1> month_start_{};
    std::array<char, 1> day_start_{};
    std::array<char, 1> year_end_{};
    std::array<char, 1> month_end_{};
    std::array<char, 1> day_end_{};

};



// Protocol : event/frame ID (1byte), user_name_(10 bytes), room_id_(1byte), year_start_(1byte), month_start_(1byte), day_start_(1byte)
//            year_end_(1byte), month_end_(1byte), day_end_(1byte)             
class FrameRequestCancelBooking {
public:
    static FrameRequestCancelBooking& create_instance() {
        static FrameRequestCancelBooking instance;
        return instance;
    }

    const char id{3};

    static constexpr const size_t frame_size{18};

    bool parse_event(Event* event_p) {
        
        if(event_p->get_event_id() == id) {
            event_p_ = event_p;
        }
        else {
            event_p_ = nullptr;
            return false;
        }

        if (event_p_->get_event_size() != frame_size) {
            return false; // TBD: add error handling
        }
        
        const auto& data = event_p_->get_event_data();
        
        for(auto &ele : frame_index_config[id]){
            copy_from_event_to_frame(user_name_, data, std::get<0>(ele), std::get<1>(ele));
        }
        
        /*
        copy_from_event_to_frame(user_name_, data, 1, 11);
        copy_from_event_to_frame(room_id_, data, 11, 12);
        copy_from_event_to_frame(year_start_, data, 12, 13);
        copy_from_event_to_frame(month_start_, data, 13, 14);
        copy_from_event_to_frame(day_start_, data, 14, 15);
        copy_from_event_to_frame(year_end_, data, 15, 16);
        copy_from_event_to_frame(month_end_, data, 16, 17);
        copy_from_event_to_frame(day_end_, data, 17, 18);
        */

        return true;
    } 

    void print() {
        std::cout<<"print called"<<std::endl;
    }


private:
    Event* event_p_{nullptr};
    std::array<char, 10> user_name_{};
    std::array<char, 1> room_id_{};
    std::array<char, 1> year_start_{};
    std::array<char, 1> month_start_{};
    std::array<char, 1> day_start_{};
    std::array<char, 1> year_end_{};
    std::array<char, 1> month_end_{};
    std::array<char, 1> day_end_{};
};











