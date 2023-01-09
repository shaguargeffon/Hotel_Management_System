# Design and Development

This Hotel Management System simulates a real scenario that multiple clients book rooms of a hotel.

Multiple clients shall use different sockets to communicate the server.

The system shall be independent from a concret communication way like UDP, TCP etc.

The server shall support multi-threading on Linux system.

The server shall be implemented by C/C++ language and follow C++ guideline.

The client shall be implemented by C/C++ or python.

The data base shall be designed flexibel and reliable.

The data base shall be embedded in Linux system.

The data base shall be able to read from a local file.

The data base shall be able to written to a local file.

The communication protocals between the server and client shall be defined and cover all use cases.

The communication protocals shall be designed as Plug-In to make the system flexible.

The communication protocals shall be synchronized between the server and client when the system starts.

The development shall follow TDD approach to ensure that the system is always working.

The integration test shall be performed on the client side for testing the server behavior.

The unit test shall be performed both on the server and client side.

The error handling shall cover all use cases and possbile errors.

The warning handling shall cover all use cases and possible warnings.

The security shall be ensured during communication of server and client.

The logging data shall be able to written to a log file for debugging/checking.

The SW design shall follow OOP design principle.


# Functionalities of the hotel management system

Register account : Done

Unregister account : Done

Login : Done

Logout : Done

Booking a room : in process

Cancel a room : not started

Modify Booking : not started

Query booking information : not started

Download booking information : not started

Modify client information : not started

# How to run the system

## conditions

Install python on Ubuntu : sudo apt install python3.9  (Python2 shall be also working)

Install CMAKE on Ubuntu : sudo apt install cmake

Install g++ on Ubuntu : sudo apt install g++ 

Install gcc on Ubuntu : sudo apt install gcc

## Steps

Reach the folder /hotel/Hotel_Management_System/build : cd hotel/Hotel_Management_System/build

run the command : cmake ..
run the command : make

After building the executable/binary file is located in build which is called myhotel

run the command from build folder to start the server : ./myhotel

open a new terminal and reach the folder /hotel/Hotel_Management_System/client : cd hotel/Hotel_Management_System/client

run the command : python integration_test.py

Then the implemented integration test cases will be running and report the result which is printed on the terminal

# To Be Done

Redesign the arrangement of software components.

The current data base is still in POC process, for instance later sqlite3 will be tried.

The case that the Handler pointer is a nullptr shall be handled.

The error handling will be extended.

Clean code shall be followed.

Refactor the code to remove bad coding smell shall be done during the development.

Software Architecture may be optimized, for instance to use abstract class instead of a concret class.

Unit test will be done on both side.

Integration test will be extended according to use case.

Synchronization of communication protocals between server and client will be implemented.

File format and data structure for the synchronization shall be designed.

Multi-threading for server will be implemented to support multiple clients requests.

Basic Types shall be redefined.

Algorithm optimization shall be done.

Client Software Architecture shall be redefined.

Heap-Pointer shall be considered to be designed by using stack pointer.

More template generic design shall be considered.

It shall be designed and implemented that after login the server shall deploy a token for the connected client for security.

The documentation for software architecture, communication frame defination and unit design shall be done.
