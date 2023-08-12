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


class Event {
public:
Event(char event_id, char* data, size_t size): event_id_(event_id), size_(size) {
    for(size_t i=0; i<size_; i++){
        data_.push_back(data[i]);
    }
}

bool operator==(Event& e) const{
    return this->event_id_ == e.event_id_;
}

char get_event_id() {
    return event_id_;
}

size_t get_event_size() {
    return data_.size();
}

std::vector<char>& get_event_data() {
    return data_;
}


private:
char event_id_;
std::vector<char> data_;
size_t size_;
};

