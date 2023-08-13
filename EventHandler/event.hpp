#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include <vector>
#include <memory>
#include <optional>


class Event {
public:
    Event(char event_id, const char* data, size_t size): event_id_(event_id), data_(std::string{data, size}), size_(size) {
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

    std::string& get_event_data() {
        return data_;
    }

private:
    char event_id_;
    std::string data_;
    size_t size_;
};

