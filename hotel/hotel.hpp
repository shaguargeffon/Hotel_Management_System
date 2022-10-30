#pragma once
/*

#include <vector>
#include <string>
#include <algorithm>

class Hotel
{
protected:
static unsigned long hotel_room_booking_id;


public:
    virtual bool find_room(unsigned int room_id_, Room* room) = 0;

    virtual bool modify_booking_ID(unsigned int room_id_, unsigned long booking_id_) = 0;

    virtual bool allocate_booking_ID(unsigned int room_id_) = 0;

    virtual bool modify_room_price(unsigned int room_id_, unsigned int new_price_) = 0;

    virtual bool modify_sub_rooms(unsigned int room_id_, unsigned int amount_sub_room_) = 0;

    virtual bool modify_room_size(unsigned int room_id_, unsigned int room_size_) = 0;
};


unsigned long Hotel::hotel_room_booking_id{1};


class StandardHotel: public Hotel
{
public:

    virtual bool find_room(unsigned int room_id_, Room* room)
    {
        auto room_it = find(rooms.begin(), rooms.end(), Room(room_id_));
        
        bool res{false};
        
        if(room_it != rooms.end())
        {
            room = &(*room_it);
            res = true;
        }

        return res;
    }


    virtual bool modify_booking_ID(unsigned int room_id_, unsigned long booking_id_)
    {
        Room* room_p{nullptr};
        
        bool res = find_room(room_id_, room_p);

        if(res)
        {
            room_p->set_booking_ID(booking_id_);
        }

        return res;
    }


    virtual bool allocate_booking_ID(unsigned int room_id_)
    {
        Room* room_p{nullptr};
        
        bool res = find_room(room_id_, room_p);

        if(res)
        {
            room_p->set_booking_ID(Hotel::hotel_room_booking_id++);
        }

        return res;
    }



    virtual bool modify_room_price(unsigned int room_id_, unsigned int new_price_)
    {
        Room* room_p{nullptr};
        
        bool res = find_room(room_id_, room_p);

        if(res)
        {
            room_p->set_price(new_price_);
        }

        return res;
    }


    virtual bool modify_sub_rooms(unsigned int room_id_, unsigned int amount_sub_room_)
    {
        Room* room_p{nullptr};
        
        bool res = find_room(room_id_, room_p);

        if(res)
        {
            room_p->set_amount_sub_rooms(amount_sub_room_);
        }

        return res;
    }


    virtual bool modify_room_size(unsigned int room_id_, unsigned int room_size_)
    {
        Room* room_p{nullptr};
        
        bool res = find_room(room_id_, room_p);

        if(res)
        {
            room_p->set_room_size(room_size_);
        }

        return res;
    }

private:
    std::vector<Room> rooms;

};



class Room
{
public:

    Room() = delete;

    explicit Room(unsigned int room_id_)
    {
        room_id = room_id_;
    }


    explicit Room(const Room& room)
    {
        this->booking_ID = room.booking_ID;
        this->room_id = room.room_id;
        this->amount_sub_rooms = room.amount_sub_rooms;
        this->room_size = room.room_size;
        this->price = room.price;
    }


    bool operator==(const Room& room) const
    {
        return (this->room_id == room.room_id);
    }


    Room& operator=(const Room& room)
    {
        this->booking_ID = room.booking_ID;
        this->room_id = room.room_id;
        this->amount_sub_rooms = room.amount_sub_rooms;
        this->room_size = room.room_size;
        this->price = room.price;

        return *this;
    }


    //setter
    void set_booking_ID(unsigned long id_)
    {
        booking_ID = id_;
    }

    void set_room_ID(unsigned int number_)
    {
        room_id = number_;
    }

    void set_amount_sub_rooms(unsigned int amount_)
    {
        amount_sub_rooms = amount_;
    }

    void set_room_size(unsigned int size_)
    {
        room_size = size_;
    }

    void set_price(unsigned int price_)
    {
        this->price = price_;
    }


    //getter
    unsigned int get_booking_ID()
    {
        return booking_ID;
    }

    unsigned int get_room_ID()
    {
        return room_id;
    }

    unsigned int get_amount_sub_rooms()
    {
        return amount_sub_rooms;
    }

    unsigned int get_room_size()
    {
        return room_size;
    }

    unsigned int get_price()
    {
        return price;
    }

    bool is_room_booked()
    {
        return (booking_ID != 0) ;
    }


private:
    unsigned long booking_ID{0};
    unsigned int room_id{0};
    unsigned int amount_sub_rooms{0};
    unsigned int room_size{0};
    unsigned int price{0};

};



*/

