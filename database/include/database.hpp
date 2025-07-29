//***************************************************************************************
// Copyright (C) Han Di
//***************************************************************************************

/**
 *  \file
 *      database.hpp
 *
 *  \brief
 *      Declaration of DataBase class
 *
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <string>
#include "sqlite3.h"

namespace hotel {
namespace database{

static std::string const kCreateTableCommand{"create table "};
static std::string const kDataSetName{"hotel"};
static std::string const kDataBaseName{"hotel.db"};

void callback(){
    
}


template<typename T>
class DataBase{
public:
    DataBase(T hotel_config): hotel_config_(hotel_config){}

    bool CreateHotelDataBase(){
        sqlite3 *database_p{nullptr};

        char *zErrMsg = 0;

        int rc;

        // const char *sql;

        rc = sqlite3_open(hotel_config_.GetDataBaseName(), &database_p); // 打开数据库

        if (rc)
        {
            std::cerr << "Can't open database: " << sqlite3_errmsg(database_p) << std::endl;
            return false;
        }
        else
        {
            std::cout << "open database succeddfully" << std::endl;
        }

        // sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";
        const std::string command = kCreateTableCommand + kDataSetName + std::string{"(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))"};
        char const *sql = command.c_str();
        //std::cout << "sql: " << *sql << std::endl;

        rc = sqlite3_exec(database_p, sql, callback, 0, &zErrMsg); // 执行上面sql中的命令

        if (SQLITE_OK != rc)
        {
            std::cerr << "SQL error: " << zErrMsg << std::endl;
        }
        else
        {
            std::cout << "create table successfully" << std::endl;
        }

        sqlite3_close(database_p);

        return true;
    }

private:
    T hotel_config_;
};


} // namspace database

} // namespace hotel

#endif
