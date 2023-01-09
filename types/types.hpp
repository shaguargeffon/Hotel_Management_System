#pragma once

#include <iostream>
#include <string.h>


    struct Client
    {
        //Client() = delete;

        Client(){} // only for creating a temporary instance

        explicit Client(char* client_id_p)
        {
            for(int i=0; i<5; i++)
            {
                id[i] = client_id_p[i];
            }
        }

        Client(char* client_id_p, char* pw)
        {
            for(int i=0; i<5; i++)
            {
                id[i] = client_id_p[i];
            }

            memcpy(password, pw, 8);
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


        bool compare_password(char* pw) const
        {
            return memcmp(password, pw, 8)==0;
        }

        void set_login_status(bool login_status)
        {
            is_login = login_status;
        }

        bool get_login_status() const
        {
            return is_login;
        }

        char id[5];
        char password[8];
        //CLIENTNAME_T name;
        char priority{0};
        bool is_login{false};
    };



    struct Room
    {
        Room() = default;

        Room(char* room_id)
        {
            memcpy(id, room_id, 3);
        }

        char id[3];

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

        Date(){}

        Date(char* day_p, char* month_p, char* year_p)
        {
            memcpy(day, day_p, 2);
            memcpy(month, month_p, 2);
            memcpy(year, year_p, 4);
        }

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

        char day[2];
        char month[2];
        char year[4];
    };


