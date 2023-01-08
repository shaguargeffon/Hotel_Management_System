#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "types.hpp"

//Rule of Three design
class ITEM
{
public:

    //Reason to enable the default constructor: In template class it is needed.
    ITEM()
    {

    }

    explicit ITEM(Client client_p): client(client_p)
    {

    }

    //default copy constructor
    ITEM(const ITEM& item) = default;

    //default copy assignment
    ITEM& operator=(const ITEM& item) = default;

    //deleted move constructor
    ITEM(ITEM&& item) noexcept = delete;

    //deleted assignment constructor
    ITEM& operator=(ITEM&& item) noexcept = delete;


    ~ITEM() = default;

    bool operator==(const ITEM& item) const
    {
        return this->client == item.client;
    }

    bool operator<(const ITEM& item) const
    {
        return this->client.priority < item.client.priority;
    }

    bool booking(Room room, std::set<Date> dates)
    {
        auto iter = info.find(room); // The API "contains" can't be used since the project only supports C++ 11, 14 or 17.

        if(iter == info.end()) // room is not found, booking fails
        {
            return false;
        }

        std::vector<Date> temp_vector(info[room].size() + dates.size());
            
        (void)std::set_intersection(info[room].begin(), info[room].end(), dates.begin(), dates.end(), temp_vector.begin());

        if(temp_vector.size() > 0) // there is intersection available, booking fails
        {
            return false;
        }

        (void)std::merge(info[room].begin(), info[room].end(), dates.begin(), dates.end(), temp_vector.begin());

        std::set<Date> temp_set(temp_vector.begin(), temp_vector.end());

        info[room] = temp_set;

        return true;
    }


    bool cancel_booking(Room room, std::set<Date> dates)
    {
        auto iter = info.find(room); // The API "contains" can't be used since the project only supports C++ 11, 14 or 17.

        if(iter == info.end()) // room is not found
        {
            return false;
        }

        bool is_cancel_dates_included = std::includes(info[room].begin(), info[room].end(), dates.begin(), dates.end());

        if(is_cancel_dates_included)
        {
            std::vector<Date> temp_vector(info[room].size());

            auto it = std::set_difference(info[room].begin(), info[room].end(), dates.begin(), dates.end(), temp_vector.begin());

            temp_vector.resize(std::distance(temp_vector.begin(), it));

            if(temp_vector.size() == 0) // canceled all dates for this room, the room-date pair shall be removed
            {
                info.erase(room);
            }
            else
            {
                std::set<Date> temp_set(temp_vector.begin(), temp_vector.end());

                info[room] = temp_set; // use the difference part to overwrite the original set -> remove the intersection
            }

            return true;
        }

        return false; 
    }

    //overloading cancel_booking, cancel all booking for a room
    bool cancel_booking(Room room)
    {
        auto iter = info.find(room); // The API "contains" can't be used since the project only supports C++ 11, 14 or 17.

        if(iter == info.end()) // room is not found
        {
            return false;
        }

        info.erase(room);

        return true; 
    }

    Client get_client() const
    {
        return client;
    }


    void modify_login_status(bool login)
    {
        client.set_login_status(login);
    }


private:
    Client client;
    std::map<Room, std::set<Date>> info;
};
