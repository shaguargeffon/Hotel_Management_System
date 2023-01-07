#pragma once

#include <iostream>
#include <string.h>


    struct Client
    {
        Client() = delete;

        explicit Client(char* client_id_p): priority(0) 
        {
            for(int i=0; i<5; i++)
            {
                id[i] = client_id_p[i];
            }
        }

        ~Client() = default;

        bool operator<(const Client& client) const
        {
            return this->priority < client.priority;
        }

        bool operator==(const Client& client) const
        {
            for(int i=0; i<5; i++)
            {
                if(id[i] == client.id[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            
            return true;
        }

        char id[5];
        char password[8];
        //CLIENTNAME_T name;
        char priority;

    };



    struct Room
    {
        uint16_t id;

        bool operator==(const Room& room) const
        {
            return id == room.id;
        }

        bool operator<(const Room& room) const
        {
            return id < room.id;
        }
    };


    struct Date
    {
        bool operator==(const Date& date) const
        {
            return (day==date.day && month==date.month && year==date.year);
        }

        bool operator<(const Date& date) const
        {
            bool res{false};

            if(year < date.year)
            {
                res = true;
            }
            else if(year == date.year)
            {
                if(month < date.month)
                {
                    res = true;
                }
                else if(month == date.month)
                {
                    if(day < date.day)
                    {
                        res = true;
                    }
                }
                else
                {

                }
            }
            else
            {

            }

            return res;
        }

        uint8_t day;
        uint8_t month;
        uint16_t year;
    };


