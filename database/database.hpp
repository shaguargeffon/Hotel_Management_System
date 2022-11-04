#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string.h>
#include <vector>

using namespace std;


class DataBase
{

public:
    virtual int open_database()=0;
    virtual void close_database()=0;
    virtual void create_table(const string& table)=0;
    virtual int insert_item(const string& table)=0;
    virtual int delete_item(const string& table)=0;
    virtual int update(const string& table)=0;
    virtual int find_current_table_max_key(const string& table_name, const string& key, int& max_key)=0;
    virtual int find_all(const string& table, vector<string>& array_key, vector<vector<string>>& array_value)=0;
};





class CustomerDataBase: public DataBase
{
public:

    CustomerDataBase(const char *db_name): db(NULL), database_name(db_name)
    {
    }


    int open_database() final
    {
        return sqlite3_open(data_base_path.c_str(), &db);
    }


    void create_table(const string& table) final
    {
        char *szMsg = NULL;
        sqlite3_exec(db, table.c_str(), NULL,  NULL, &szMsg); 
    }


    int insert_item(const string& table) final
    {
        if(table.empty())
        {
            return -1;
        }

        char *zErrMsg = NULL;

        int ret = sqlite3_exec(db, table.c_str(), NULL,  NULL, &zErrMsg); 

        if(zErrMsg)
        {
            sqlite3_free(zErrMsg);
        }

        return ret;
    }


    int delete_item(const string& table) final
    {
        int column{0};
        int row{0};

        char **res = NULL;

        char *errMsg = NULL;

        int result = sqlite3_get_table(db, table.c_str(), &res, &row, &column, &errMsg);

        if(result != SQLITE_OK)
        {
            return -1;
        }

        if(res)
        {
            sqlite3_free_table(res);
        }

        if(errMsg)
        {
            sqlite3_free(errMsg);
        }


        return 0;
    }



    int update(const string& table) final
    {
        char* zErrMsg = NULL;

        int ret = sqlite3_exec(db, table.c_str(), NULL, NULL, &zErrMsg);

        if(zErrMsg)
        {
            sqlite3_free(zErrMsg);
        }

        return ret;
    }


    int find_current_table_max_key(const string& table_name, const string& key, int& max_key) final
    {
        max_key = -1;

        if(table_name.empty() || key.empty())
        {
            return -1;
        }

        string sql = "select * from" + table_name;

        int column = -1;
        int row = -1;
        int index = -1;
        char** res = NULL;
        char *errMsg = NULL;

        int result = sqlite3_get_table(db, sql.c_str(), &res, &row, &column, &errMsg);

        index = column;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                string s1 = res[j];
                //string s2 = res[index];
                if(s1 == key)
                {
                    max_key = atoi(res[index]);
                }

                index++;
            }
        }

        if(res)
        {
            sqlite3_free_table(res);
        }

        if(errMsg)
        {
            sqlite3_free(errMsg);
        }

        return result;
    }


    int find_all(const string& table, vector<string>& array_key, vector<vector<string>>& array_value) final
    {
        if(table.empty())
        {
            return -1;
        }

        int column = 0;
        int row = 0;
        char** res = NULL;
        char *errMsg = NULL;
        int index = 0;

        const int result = sqlite3_get_table(db, table.c_str(), &res, &row, &column, &errMsg);

        index = column;
        array_key.clear();
        array_key.reserve(column);
        array_value.clear();
        array_value.reserve(row);    

        bool is_key_captured{false};

        for(int i=0; i<row; i++)
        {
            vector<string> temp;
            for(int j=0; j<column; j++)
            {
                if(!is_key_captured)
                {
                    array_key.push_back(res[j]);
                }

                temp.push_back(res[index]);
                index++;
            }

            is_key_captured = true;
            array_value.push_back(temp);
        }

        if(res)
        {
            sqlite3_free_table(res);
        }

        if(errMsg)
        {
            sqlite3_free(errMsg);
        }

        return result;
    }




    void close_database() final
    {
        sqlite3_close(db);
    }


    ~CustomerDataBase()
    {
        if(db)
        {
            close_database();
            db = NULL;
        }
    }


private:
    //char table[256];
    sqlite3 *db;
    string data_base_path;

};

