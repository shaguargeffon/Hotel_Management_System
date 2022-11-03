add_library(sql_lib sqlite3.c)

set_target_properties(sql_lib PROPERTIES OUTPUT_NAME "sql_lib")
