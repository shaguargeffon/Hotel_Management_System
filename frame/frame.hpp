#pragma once

#include <array>
#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include <tuple>
#include "config.hpp"
#include "event.hpp"


template<typename Frame, typename Event>
static bool copy_from_event_to_frame(Frame& frame_container, Event& event_container, size_t start_index, size_t end_index) {
    frame_container = event_container.substr(start_index, end_index - start_index);
    return true;   
}


// Protocol : event/frame ID (1byte), user name (10 bytes), password (10 bytes), email(20 bytes) 
class FrameRequestRegisterNewAccount {
public:
    static FrameRequestRegisterNewAccount& get_instance() {
        static FrameRequestRegisterNewAccount instance;
        return instance;
    }

    const char id{'1'};
    static constexpr const size_t frame_size{41};

    bool parse_event(Event* event_p) {
        
        if(event_p->get_event_id() == id) {
            event_p_ = event_p;
            std::cout<<"FrameRequestRegisterNewAccount is mapped"<<std::endl;
        }
        else {
            event_p_ = nullptr;
            return false;
        }
        
        if (event_p_->get_event_size() != frame_size) {
            std::cout<<"FrameRequestRegisterNewAccount frame is not valid"<<std::endl;
            return false; // TBD: add error handling
        }
        
        const auto& data = event_p_->get_event_data();
        
        copy_from_event_to_frame(user_name_, data, 1, 11);
        copy_from_event_to_frame(password_, data, 11, 21);
        copy_from_event_to_frame(email_, data, 21, 41);
        
        return true;
    } 

private:
    Event* event_p_{nullptr};
    std::string user_name_{};
    std::string password_{};
    std::string email_{};
};



// Protocol : event/frame ID (1byte), user_name_(10 bytes), room_id_(3bytes), year_start_(4bytes), month_start_(2bytes), day_start_(2bytes)
//            year_end_(4bytes), month_end_(2bytes), day_end_(2bytes) 
class FrameRequestBookHotel {
public:
    static FrameRequestBookHotel& get_instance() {
        static FrameRequestBookHotel instance;
        return instance;
    }

    const char id{'2'};

    static constexpr size_t frame_size{31};

    bool parse_event(Event* event_p) {
        
        if(event_p->get_event_id() == id) {
            event_p_ = event_p;
            std::cout<<"FrameRequestBookHotel is mapped"<<std::endl;
        }
        else {
            event_p_ = nullptr;
            return false;
        }

        if (event_p_->get_event_size() != frame_size) {
            std::cout<<"FrameRequestBookHotel frame is not valid"<<std::endl;
            std::cout<<"event size: "<<event_p_->get_event_size()<<std::endl;
            std::cout<<"frame size: "<<frame_size<<std::endl;
            return false; // TBD: add error handling
        }
        
        const auto& data = event_p_->get_event_data();
        
        copy_from_event_to_frame(user_name_, data, 1, 11);
        copy_from_event_to_frame(room_id_, data, 11, 14);
        copy_from_event_to_frame(year_start_, data, 14, 18);
        copy_from_event_to_frame(month_start_, data, 18, 20);
        copy_from_event_to_frame(day_start_, data, 20, 22);
        copy_from_event_to_frame(year_end_, data, 22, 26);
        copy_from_event_to_frame(month_end_, data, 26, 28);
        copy_from_event_to_frame(day_end_, data, 28, 30);

        return true;
    } 

private:
    Event* event_p_{nullptr};
    std::string user_name_{};
    std::string room_id_{};
    std::string year_start_{};
    std::string month_start_{};
    std::string day_start_{};
    std::string year_end_{};
    std::string month_end_{};
    std::string day_end_{};

};



// Protocol : event/frame ID (1byte), user_name_(10 bytes), room_id_(3bytes), year_start_(4bytes), month_start_(2bytes), day_start_(2bytes)
//            year_end_(4bytes), month_end_(2bytes), day_end_(2bytes)            
class FrameRequestCancelBooking {
public:
    static FrameRequestCancelBooking& get_instance() {
        static FrameRequestCancelBooking instance;
        return instance;
    }

    const char id{'3'};

    static constexpr const size_t frame_size{31};

    bool parse_event(Event* event_p) {
        
        if(event_p->get_event_id() == id) {
            event_p_ = event_p;
            std::cout<<"FrameRequestCancelBooking is mapped"<<std::endl;
        }
        else {
            event_p_ = nullptr;
            return false;
        }

        if (event_p_->get_event_size() != frame_size) {
            std::cout<<"FrameRequestCancelBooking frame is not valid"<<std::endl;
            return false; // TBD: add error handling
        }
        
        const auto& data = event_p_->get_event_data();
        
        copy_from_event_to_frame(user_name_, data, 1, 11);
        copy_from_event_to_frame(room_id_, data, 11, 14);
        copy_from_event_to_frame(year_start_, data, 14, 18);
        copy_from_event_to_frame(month_start_, data, 18, 20);
        copy_from_event_to_frame(day_start_, data, 20, 22);
        copy_from_event_to_frame(year_end_, data, 22, 26);
        copy_from_event_to_frame(month_end_, data, 26, 28);
        copy_from_event_to_frame(day_end_, data, 28, 30);

        return true;
    } 

    void print() {
        std::cout<<"print called"<<std::endl;
    }


private:
    Event* event_p_{nullptr};
    std::string user_name_{};
    std::string room_id_{};
    std::string year_start_{};
    std::string month_start_{};
    std::string day_start_{};
    std::string year_end_{};
    std::string month_end_{};
    std::string day_end_{};
};











