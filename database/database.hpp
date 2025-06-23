#pragma once

#include <iostream>
#include <string>


#include "sqlite3.h"
//#include "thirdparty/SQLiteCpp/include/SQLiteCpp/SQLiteCppExport.h"
//#include "thirdparty/SQLiteCpp/include/SQLiteCpp/SQLiteCpp.h"


#include "database_config.hpp"





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

/* Client-ID, Name, Password, Email, Address, Telefone, Room-Number, Date */
template<typename ITEM>
class DataBaseConfig{
public:
    inline static std::string const database_name = "hotel_databse.db";
    inline static std::string const table_name = "client";
    
    inline static std::string const command_create_table = "create table";
    inline static std::string const command_insert_item = "insert into";
    
    inline static std::string const command_client_id = ITEM::ID;
    inline static std::string const command_client_id_description = ITEM::ID_description;
    
    inline static std::string const command_client_name = ITEM::name;
    inline static std::string const command_client_name_description = ITEM::name_description;
    
    inline static std::string const command_password = ITEM::password;
    inline static std::string const command_password_description = ITEM::password_description;

    inline static std::string const command_email = ITEM::email;
    inline static std::string const command_email_description = ITEM::email_description;

    inline static std::string const command_address = ITEM::address;
    inline static std::string const command_address_description = ITEM::address_description;

    inline static std::string const command_telefone = ITEM::password;
    inline static std::string const command_telefone_description = ITEM::telefone_description;

    inline static std::string const command_room = ITEM::room;
    inline static std::string const command_room_description = ITEM::room_description;

    inline static std::string const command_date = ITEM::date;
    inline static std::string const command_date_description = ITEM::date_description;

//ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50)

};


//template <typename DBC>
class DataBase
{
public:

    static constexpr const char* database_name_{"hotel_databse.db"};



    static DataBase& get_instance() {
        static DataBase instance;
        return instance;
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

        //sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";
        const std::string command = std::string{"create table "} + std::string{"company"} + std::string{"(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))"};
        sql = command.c_str();
        std::cout<<"sql: "<<*sql<<std::endl;


        rc = sqlite3_exec(database_p, sql, callback, 0, &zErrMsg); // 执行上面sql中的命令
    
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

        rc = sqlite3_exec(database_p, sql, callback2, 0, &zErrMsg);
    
        if(SQLITE_OK != rc) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
        }
        else {
            fprintf(stdout, "insert table successfully\n");
        }

        sqlite3_close(database_p);

        return true;
    }


    static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
        std::cout<<"Count of columen: "<<argc<<std::endl;
        
        if(NotUsed != NULL) 
        { 
            printf("%s\n", (char*)NotUsed); 
        } 

        for(int x=0 ; x<argc; x++) 
        { 
            //if(strcmp(azColName[x],"tbl_name")==0) 
            //    printf("%s : %s\n", azColName[x], argv[x]);
            std::cout<<argv[x]<<std::endl; 
        }        
        
        return 0; 
    }

    static int callback2(void *NotUsed, int argc, char **argv, char **azColName) {
   
        
        return 0; 
    }


    bool query_data() {
        sqlite3* database_p;
        char *zErrMsg = 0;
        int rc;            
        const char *sql =  "select * from company;";

        rc = sqlite3_open("./hotel_databse.db", &database_p);
        if(rc) {
            fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(database_p));
            return false;
        }
        else {
            fprintf(stderr,"open database succeddfully\n");
        }

        rc = sqlite3_exec(database_p, sql, callback, 0, &zErrMsg);

        if(SQLITE_OK != rc) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
        }
        else {
            fprintf(stdout, "select table successfully\n");
        }

        sqlite3_close(database_p);

        return true;
    }

    bool update_item() {
        sqlite3* db;
        char *zErrMsg = 0;
        int rc;
        char *sql;

        rc = sqlite3_open("./hotel_databse.db", &db);
    
        if(rc)
        {
            fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(db));
            //        exit(0);
            return -1;
        }
        else
        {
            fprintf(stderr,"open database succeddfully\n");
        }

        sql = "update  company set ADDRESS = 'RUS' where ID = 3;\
            select * from company;";

        rc = sqlite3_exec(db, sql, callback2, 0, &zErrMsg);
        
        if(SQLITE_OK != rc)
        {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
        }
        else
        {
            fprintf(stdout, "update table successfully\n");
        }

        sqlite3_close(db);
       
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
    

    
    bool find_item_of_db() {
        return true;
    }


private:
    char *zErrMsg;
    std::string item_;
    //CB_T callback_dict;
};



