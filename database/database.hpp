#pragma once

#include <iostream>
#include <sqlite3.h>



using namespace std;


class DataBase
{

public:
    virtual int open_database()=0;


};







class CustomerDataBase: public DataBase
{
public:

    CustomerDataBase(const char *db_name): db(NULL), database_name(db_name)
    {
    }

    int open_database() final
    {
        int rc = sqlite3_open(database_name, &db);
        return rc;
    }


private:
    sqlite3 *db;
    const char *database_name;

};

