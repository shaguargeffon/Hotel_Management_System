#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string.h>


using namespace std;


class DataBase
{

public:
    virtual int open_database()=0;
    virtual void close_database()=0;
    virtual void create_table()=0;
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
        
        memset(table, '\0', 256);
        return rc;
    }

    void create_table() final
    {
        strcpy(table, "create table tb(id INTEGER PRIMARY KEY, data TEXT)");
        sqlite3_exec(db, table, NULL,  NULL, NULL); 
    }

    void close_database() final
    {
        sqlite3_close(db);
    }



private:
    char table[256];
    sqlite3 *db;
    const char *database_name;

};

