import socket
import time

class Test:
    @classmethod
    def configure(cls):
        #cls.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        cls.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        #cls.socket.connect(("10.0.2.15", 8888))
        #cls.socket.connect(("shaguar-VirtualBox", 8888))
        cls.socket.connect(("192.168.2.185", 8888))

        # Client Info
        cls.client_id = "12345"
        cls.client_password = "32362266"
       
        # Error Code
        cls.negative_response_id = "FF"

        cls.error_client_register_failed = "CRF"
        cls.error_client_not_found = "CNF"
        cls.error_password_not_identical = "PNI"
        cls.error_login_repeat = "LIR"
        cls.error_logout_repeat = "LOR"

        # Register and Unregister message
        cls.register_request_id = "10"
        cls.unregister_request_id = "11"
        cls.register_response_id = "50"
        cls.unregister_response_id = "51"

        
        cls.register_request_message = cls.register_request_id + cls.client_id + cls.client_password
        cls.unregister_request_message = cls.unregister_request_id + cls.client_id + cls.client_password
        
        cls.register_response_positive_message = cls.register_response_id + cls.client_id
        cls.unregister_response_positive_message = cls.unregister_response_id + cls.client_id

        cls.register_response_negative_message = cls.negative_response_id + cls.client_id + cls.error_client_register_failed
        cls.unregister_response_client_not_found = cls.negative_response_id + cls.client_id + cls.error_client_not_found
        cls.unregister_response_password_not_identical = cls.negative_response_id + cls.client_id + cls.error_password_not_identical


        # Login and Logout message
        cls.login_request_id = "20"
        cls.logout_request_id = "21"

        cls.login_response_id = "60"
        cls.logout_response_id = "61"

        cls.login_request_message = cls.login_request_id + cls.client_id + cls.client_password
        cls.logout_request_message = cls.logout_request_id + cls.client_id + cls.client_password

        cls.login_response_positive_message = cls.login_response_id + cls.client_id
        cls.logout_response_positive_message = cls.logout_response_id + cls.client_id

        cls.login_response_client_not_found = cls.negative_response_id + cls.client_id + cls.error_client_not_found
        cls.login_response_password_not_identical = cls.negative_response_id + cls.client_id + cls.error_password_not_identical
        cls.login_response_login_repeat = cls.negative_response_id + cls.client_id + cls.error_login_repeat
        cls.logout_response_client_not_found = cls.negative_response_id + cls.client_id + cls.error_client_not_found
        cls.logout_response_password_not_identical = cls.negative_response_id + cls.client_id + cls.error_password_not_identical
        cls.logout_response_logout_repeat = cls.negative_response_id + cls.client_id + cls.error_logout_repeat
        #cls.close()

class TestSocket(Test):
    @classmethod
    def test_socket_receive(cls):
        #Test.configure()
        message = Test.socket.recv(1024)
        #print("received data: ", message)
        return message


class TestRegisterUnregister(Test):


    @classmethod
    def test_case_1(cls):
        
        Test.socket.send(Test.register_request_message.encode('utf-8'))

        register_response_message = Test.socket.recv(1024)

        if register_response_message.decode('utf-8') == Test.register_response_positive_message:
            print("Integration Test Case 1 : one time Register : OK")
        else:
            print("Test case 1: register response message: ", register_response_message)

        time.sleep(2)

        Test.socket.send(Test.unregister_request_message.encode('utf-8'))

        unregister_response_message = Test.socket.recv(1024)

        if unregister_response_message.decode('utf-8') == Test.unregister_response_positive_message:
            print("Integration Test Case 1 : Unregister after register : OK")
        else:
            print("Test case 1: unregister response message: ", unregister_response_message.encode)

        time.sleep(2)


    @classmethod
    def test_case_2(cls):
        
        Test.socket.send(Test.register_request_message.encode('utf-8'))

        register_response_message = Test.socket.recv(1024)

        if register_response_message.decode('utf-8') == Test.register_response_positive_message:
            print("Integration Test Case 2 : one time Register : OK")
        else:
            print("Test case 2: first register response message: ", register_response_message)

        time.sleep(2)

        Test.socket.send(Test.register_request_message.encode('utf-8')) # send a register request again

        register_response_message = Test.socket.recv(1024)

        if register_response_message.decode('utf-8') == Test.register_response_negative_message:
            print("Integration Test Case 2 : Repeate Register request : OK")
        else:
            print("Test case 2: second register response message: ", register_response_message)


        time.sleep(2)

        # To recover the status for next test case
        Test.socket.send(Test.unregister_request_message.encode('utf-8'))

        unregister_response_message = Test.socket.recv(1024)

        if unregister_response_message.decode('utf-8') == Test.unregister_response_positive_message:
            print("Integration Test Case 2 : Unregister after register : OK")
        else:
            print("Test case 2: unregister response message: ", unregister_response_message)
 
        time.sleep(2)


    @classmethod
    def test_case_3(cls):
        
        Test.socket.send(Test.register_request_message.encode('utf-8'))

        register_response_message = Test.socket.recv(1024)
        
        if register_response_message.decode('utf-8') == Test.register_response_positive_message:
            print("Integration Test Case 3 : one time Register : OK")
        else:
            print("Integration Test case 3 Error: register response message: Fail: ", register_response_message)

        time.sleep(2)

        Test.socket.send(Test.login_request_message.encode('utf-8')) # send a login request

        login_response_message = Test.socket.recv(1024)

        if login_response_message.decode('utf-8') == Test.login_response_positive_message:
            print("Integration Test Case 3 : Positive login response : OK")
        else:
            print("Integration Test case 3: Positive login response: Fail: ", login_response_message)

        time.sleep(2)

        Test.socket.send(Test.login_request_message.encode('utf-8')) # send a login request again

        login_response_message = Test.socket.recv(1024)

        if login_response_message.decode('utf-8') == Test.login_response_login_repeat:
            print("Integration Test Case 3 : Login repeated : OK")
        else:
            print("Integration Test case 3: Login repeated: Fail: ", login_response_message)


        time.sleep(2)

        # To recover the status for next test case
        Test.socket.send(Test.logout_request_message.encode('utf-8')) # send a logout request

        logout_response_message = Test.socket.recv(1024)

        if logout_response_message .decode('utf-8')== Test.logout_response_positive_message:
            print("Integration Test Case 3 : Positive logout response : OK")
        else:
            print("Test case 3: Positive logout response: Fail: ", logout_response_message)


        time.sleep(2)

        Test.socket.send(Test.logout_request_message.encode('utf-8')) # send a logout request again

        logout_response_message = Test.socket.recv(1024)
 
        if logout_response_message.decode('utf-8') == Test.logout_response_logout_repeat:
            print("Integration Test Case 3 : Logout repeated : OK")
        else:
            print("Test case 3: Logout repeated: Fail: ", logout_response_message)
 

if __name__ == '__main__':
    Test.configure()

    while True:

        data = TestSocket.test_socket_receive()
        print(f"Received {data!r}")
        time.sleep(1)
        #Test.socket.send(data)
        #time.sleep(1)


