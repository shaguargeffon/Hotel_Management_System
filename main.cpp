//#include <pthread.h>
#include <stdio.h>
//#include <ctype.h>
#include <unistd.h>
//#include <sys/types.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
#include <stdlib.h>
#include <string>
#include <cstring>
//#include "com.hpp"
//#include "service.hpp"
//#include "execution_manager"


//compiling command: gcc -pthread -g -o main main.c

#include "com.hpp"
#include "frame_handler.hpp"
#include "frame.hpp"
#include "event_handler.hpp"
#include "sqlite3.h"
#include "database.hpp"

//#include "boost/atomic.hpp"
#include <array>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include "boost/container/vector.hpp"


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


int createdb() {
    sqlite3* db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;

    rc = sqlite3_open("./hotel_databse.db", &db);  // 打开数据库
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

    sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg); // 执行上面sql中的命令
    if(SQLITE_OK != rc)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
    }
    else
    {
        fprintf(stdout, "create table successfully\n");
    }

    sqlite3_close(db);
    
}



int insert_data_to_db() {
    sqlite3* db;
    char *zErrMsg = 0;
    int rc;
    const char *sql = "insert into company(ID, NAME, AGE, ADDRESS) values(1, 'Paul', 25, 'USA');\
        insert into company(ID, NAME, AGE, ADDRESS) values(2, 'James', 28, 'JAP');\
        insert into company(ID, NAME, AGE, ADDRESS) values(3, 'Yao', 30, 'CHA');\
        insert into company(ID, NAME, AGE, ADDRESS) values(4, 'kobe', 38, 'USA');";

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

//    sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if(SQLITE_OK != rc)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
    }
    else
    {
        fprintf(stdout, "insert table successfully\n");
    }

    sqlite3_close(db);
}


int query_data() {
        sqlite3* db;
    char *zErrMsg = 0;
    int rc;
    const char *sql =  "select * from  company;";

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

    

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(SQLITE_OK != rc)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
    }
    else
    {
        fprintf(stdout, "select table successfully\n");
    }

    sqlite3_close(db);
}
*/




int main()
{
    /*
    COM com{8080};

    com.create_socket();
    com.attach_port_to_socket();
    com.configure_address();
    com.bind_address();
    com.listen_clients();
    com.accept_clients();
    
    while(1) {
        com.send_data(5);
        printf("Data sent\n");
        usleep(1000000);
        int receive_size = com.receive_data();
        printf("Data received\n");
        com.print_receive_data(receive_size);
        
        usleep(1000000);
    }

    com.close_socket();

    com.shutdown_socket();
    */

    //static std::tuple<> mydata;

    //using FH = RequestFrameSet<FrameRequestRegisterNewAccount, FrameRequestBookHotel, FrameRequestCancelBooking>;

    // 测试frame
     
    std::tuple<FrameRequestRegisterNewAccount, FrameRequestBookHotel, FrameRequestCancelBooking> request_frames{
        FrameRequestRegisterNewAccount::create_instance(),
        FrameRequestBookHotel::create_instance(),
        FrameRequestCancelBooking::create_instance()
    };

// Protocol : event/frame ID (1byte), user_name_(10 bytes), room_id_(3bytes), year_start_(4bytes), month_start_(2bytes), day_start_(2bytes)
//            year_end_(4bytes), month_end_(2bytes), day_end_(2bytes) 
    char test_dataset[31] = {'3', 'H', 'a', 'n', 'D', 'i', '\0', '\0', '\0', '\0', '\0', '1', '2', '3', '2', '0', '2', '3', '1', '2', '0', '1', '2', '0', '2', '3', '1', '2', '0', '5'};
    
    std::string event_id{"2"};
    std::string user_name{"HanDi\0\0\0\0\0"};
    std::string room_id{"123"};
    std::string year_start{"2023"};
    std::string month_start{"12"};
    std::string day_start{"01"};
    std::string year_end{"2023"};
    std::string month_end{"12"};
    std::string day_end{"05"};

    std::string complete_frame{event_id + user_name + room_id + year_start + month_start + day_start + year_end + month_end + day_end};
    
    Event test_event{'2', complete_frame.c_str(), 31};

    // loop over the tuple
    std::apply(
        [&test_event](auto&&... arg){
            ((arg.parse_event(&test_event)), ...);
        },
        request_frames
    );
    


    //测试数据库
    //createdb();
    //insert_data_to_db();
    //query_data();

    auto data_base = DataBase<CallBackConfig>::get_instance();


    boost::container::vector<int> test_boost_vector= {1, 2, 3, 4, 5};

    for(auto i : test_boost_vector) {
        std::cout<< i << std::endl;
    } 


    return 0;
}



