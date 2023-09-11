#pragma once

#include <iostream>
#include "sqlite3.h"
#include "database_config.hpp"
using namespace std;


class DataBaseAbs
{
public:
    virtual bool open_db() = 0;
    virtual bool close_db() = 0;
    virtual bool write_item_to_db() = 0;
    virtual bool read_item_from_db() = 0;
    virtual bool modify_item_to_db() = 0;
    virtual bool find_item_of_db() = 0;
};



template <typename CB_T>
class DataBase: public DataBaseAbs
{
public:

    static constexpr const char* database_name_{"hotel_databse.db"};

    static DataBase& get_instance() {
        static DataBase instance;
        return instance;
    }

    /*
    static int callback(void *NotUsed, int argc, char **argv, char **azColName)
    {
        int i = 0;
        
        for(i = 0; i < argc; i++)
        {
            printf("%s = %s\n",azColName[i], argv[i]?argv[i]:"NULL");
        }

        printf("\n");
        return 0;
    }
    */

    DataBase() {
        
        sqlite3* database_p{nullptr};
        
        char *zErrMsg = 0;
        
        int rc;
        
        const char *sql;

        rc = sqlite3_open(database_name_, &database_p);  // 打开数据库
    
        if(rc) {
            std::cerr<<"Can't open database: "<<sqlite3_errmsg(database_p)<<std::endl;
            return;
        }
        else {
            std::cout<<"open database succeddfully"<<std::endl;
        }

        sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";

        rc = sqlite3_exec(database_p, sql, (CB_T::get_cb_config())[0], 0, &zErrMsg); // 执行上面sql中的命令
    
        if(SQLITE_OK != rc) {
            std::cerr<<"SQL error: "<<zErrMsg<<std::endl;
        }
        else {
            std::cout<<"create table successfully"<<std::endl;
        }

        sqlite3_close(database_p);


        //callback_dict = CB_T::get_cb_config();
    }





    bool createdb() {
        sqlite3* database_p{nullptr};
        
        char *zErrMsg = 0;
        
        int rc;
        
        const char *sql;

        rc = sqlite3_open(database_name_, &database_p);  // 打开数据库
    
        if(rc) {
            std::cerr<<"Can't open database: "<<sqlite3_errmsg(database_p)<<std::endl;
            return false;
        }
        else {
            std::cout<<"open database succeddfully"<<std::endl;
        }

        sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";

        rc = sqlite3_exec(database_p, sql, (CB_T::get_cb_config())[0], 0, &zErrMsg); // 执行上面sql中的命令
    
        if(SQLITE_OK != rc) {
            std::cerr<<"SQL error: "<<zErrMsg<<std::endl;
        }
        else {
            std::cout<<"create table successfully"<<std::endl;
        }

        sqlite3_close(database_p);

        return true;
    }



    bool insert_data_to_db() {
        sqlite3* database_p;
        
        char *zErrMsg = 0;
        
        int rc;
        
        const char *sql = "insert into company(ID, NAME, AGE, ADDRESS) values(1, 'Paul', 25, 'USA');\
            insert into company(ID, NAME, AGE, ADDRESS) values(2, 'James', 28, 'JAP');\
            insert into company(ID, NAME, AGE, ADDRESS) values(3, 'Yao', 30, 'CHA');\
            insert into company(ID, NAME, AGE, ADDRESS) values(4, 'kobe', 38, 'USA');";

        rc = sqlite3_open("./hotel_databse.db", &database_p);
        
        if(rc) {
            fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(database_p));
            return false;
        }
        else {
            fprintf(stderr,"open database succeddfully\n");
        }

        rc = sqlite3_exec(database_p, sql, (CB_T::get_cb_config())[0], 0, &zErrMsg);
    
        if(SQLITE_OK != rc) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
        }
        else {
            fprintf(stdout, "insert table successfully\n");
        }

        sqlite3_close(database_p);

        return true;
    }


    bool query_data() {
        sqlite3* database_p;
        char *zErrMsg = 0;
        int rc;
        const char *sql =  "select * from  company;";

        rc = sqlite3_open("./hotel_databse.db", &database_p);
        if(rc) {
            fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(database_p));
            return false;
        }
        else {
            fprintf(stderr,"open database succeddfully\n");
        }

        rc = sqlite3_exec(database_p, sql, (CB_T::get_cb_config())[0], 0, &zErrMsg);

        if(SQLITE_OK != rc) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
        }
        else {
            fprintf(stdout, "select table successfully\n");
        }

        sqlite3_close(database_p);

        return true;
    }


    bool open_db() {
        return true;
    }
    
    bool close_db() {
        return true;
    }
    
    bool write_item_to_db() {
        return true;
    }
    
    bool read_item_from_db() {
        return true;
    }
    
    bool modify_item_to_db() {
        return true;
    }
    
    bool find_item_of_db() {
        return true;
    }


private:
    char *zErrMsg;
    //CB_T callback_dict;
};

