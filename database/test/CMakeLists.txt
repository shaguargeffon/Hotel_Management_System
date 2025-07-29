find_package(GTest REQUIRED)



add_executable(database_spec
../src/database.cpp    
database.spec.cpp
  
)

target_include_directories(database_spec
    PRIVATE
    ../include
)

target_link_libraries(database_spec
    PRIVATE
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
)


#gtest_discover_tests(database_spec)

  install(TARGETS database_spec)
