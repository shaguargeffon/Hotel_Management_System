#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <functional>
#include <stdio.h>


typedef int (*CB_T)(void*, int, char**, char**);







class CallBackConfig {
public:

    // Create callback functions
    static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
        std::cout<<"Count of columen: "<<argc<<std::endl;
        


        if(NotUsed != NULL) 
        { 
            printf("%s\n", (char*)NotUsed); 
        } 

        for(int x=0 ; x<argc; x++) 
        { 
            if(strcmp(azColName[x],"tbl_name")==0) 
                printf("%s : %s\n", azColName[x], argv[x]); 
        }        
        
        return 0; 
    }



    static std::map<const int, CB_T>& get_cb_config() {
        static std::map<const int, CB_T> CB_dict {
            {1, callback}, 
    

            {2, callback} 

    };
        
        return CB_dict; 
    }


};

/*
    static std::map<int, std::function<int(void*, int, char**, char**)>> CB_dict {
    {1, [](void *NotUsed, int argc, char **argv, char **azColName){
            int i = 0;        
            for(i = 0; i < argc; i++) {
            printf("%s = %s\n",azColName[i], argv[i]?argv[i]:"NULL");
            }

            printf("\n");
            return 0;} }

    };
*/














