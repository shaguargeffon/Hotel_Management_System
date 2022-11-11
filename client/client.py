import socket
import time

if __name__ == '__main__':

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    s.connect(("192.168.160.131", 9527))

    register_name = "10shaguarhan3236226"

    while True:
        s.send(register_name.encode('utf-8'))

        msg = s.recv(1024)

        print(msg.decode("utf-8"))
        
        time.sleep(5)

