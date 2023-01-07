#pragma once

#include <iostream>
#include <string.h>
#include <set>
#include <utility>
#include <algorithm>
#include "types.hpp"
#include "item.hpp"


template<typename T>
class AbsDataBase
{
public:

    virtual bool clear_database()=0;
    virtual bool insert_item(T& item)=0;
    virtual bool delete_item(T& item)=0;
    virtual bool update_database(T& item)=0;
    virtual std::pair<T, bool> find_item(T& item)=0;
    //virtual std::pair<T, bool> get_item(T& item)=0;
    virtual ~AbsDataBase()=default;


};




template<typename T>
class DataBase: public AbsDataBase<T>
{
public:

    bool clear_database() final
    {
        items.clear();

        return true;
    }
    
    bool insert_item(T& item) noexcept final 
    {
        auto res = items.insert(item);
        if(res.second)
        {
            return true;
        }

        return false;
    }

    bool delete_item(T& item) final
    {
        if(items.empty())
        {
            return false;
        }
        else
        {
            auto iter = find(items.begin(), items.end(), item);

            if(iter == items.end())
            {
                return false;
            }

            items.erase(iter);

            return true;
        }
    }

    bool update_database(T& item) final
    {
        auto iter = find(items.begin(), items.end(), item);

        if(iter == items.end())
        {
            return false;
        }

        items.erase(iter); // remove the old item

        items.insert(item); //insert the new item

        return true;
    }

    /*
    bool find_item(T& item) final
    {
        auto iter = find(items.begin(), items.end(), item);

        if(iter == items.end())
        {
            return false;
        }

        return true;
    }
    */

    std::pair<T, bool> find_item(T& item) final
    {
        bool res;
        
        auto iter = find(items.begin(), items.end(), item);

        if(iter == items.end())
        {
            T temp;
            auto res = std::make_pair(temp, false);
            return res;            
        }
        else
        {
            auto res = std::make_pair(*iter, true);  
            return res;   
        }
    }


private:
    std::set<T> items;
};

