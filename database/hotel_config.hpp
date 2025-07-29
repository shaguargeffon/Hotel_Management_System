//***************************************************************************************
// Copyright (C) Han Di
//***************************************************************************************

/**
 *  \file
 *      hotel_config.hpp
 *
 *  \brief
 *      Configuration about Hotel
 *
 */
#if 0
#ifndef HOTEL_CONFIG_HPP
#define HOTEL_CONFIG_HPP

#include <cstdin>
#include <string>





class HotelConfig{
public:

    std::string GetCreationTableItems() const noexcept{
        std::string const customer_member_id{"MEMBER_ID INT PRIMARY KEY NOT NULL, "};
        std::string const customer_name{"NAME TEXT NOT NULL, "};
        std::string const customer_id{"ID INT PRIMARY KEY NOT NULL, "};
        std::string const customer_telefon{"TELEFON TEXT NOT NULL, "};
        std::string const customer_email{"EMAIL TEXT NOT NULL, "};
        std::string const customer_room_date_mapping{"ROOM_DATE_MAPPING TEXT NOT NULL, "};
        std::string const customer_address{"ADDRESS CHAR(50)"};
        std::string const ret{"(" + customer_member_id + 
                                    customer_name + 
                                    customer_id + 
                                    customer_telefon + 
                                    customer_email + 
                                    customer_room_date_mapping + 
                                    customer_address + 
                                    ")"};
        return ret;
    }


    std::string& GetDataSetName() const noexcept{
        return kDataSetName;
    }

    std::string& GetDataBaseName() const noexcept{
        return kDataBaseName;
    }

"(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))"


private:
    uint8_t const kRoomAmount{100U};
    std::string const kDataSetName{"hotel"};
    std::string const kDataBaseName{"hotel.db"};

};




#endif


#endif