import socket
import time





















if __name__ == '__main__':

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    s.connect(("127.0.0.1", 9527))

    register = "101234532362266"
    unregister = "111234532362266"

    while True:
        s.send(register.encode('utf-8'))

        msg = s.recv(1024)

        print(msg.decode("utf-8"))
        
        time.sleep(5)

        s.send(unregister.encode('utf-8'))

        msg = s.recv(1024)

        print(msg.decode("utf-8"))

        time.sleep(5)

