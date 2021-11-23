import socket, sys, threading

sock = socket.socket()
port = 8080

def main():
    if sys.argv[1] == "connect":
        name = input("Name:")
        host = sys.argv[2]
        sock.connect((host, port))

        def read_sock():
            while True:
                msg = (sock.recv(1024)).decode()
                print(msg)

        thread = threading.Thread(target=read_sock)
        thread.start()

        while True:
            msg = input("")
            sock.send(("[{}]".format(name) + msg).encode())

    elif sys.argv[1] == "server":
        name = input("Name:")
        sock.bind(("0.0.0.0", port))
        sock.listen(5)
        conn, addr = sock.accept()
        print("* Connection", addr)

        def read_conn():
            while True:
                msg = (conn.recv(1024)).decode()
                print(msg)

        thread = threading.Thread(target=read_conn)
        thread.start()

        while True:
            msg = input("")
            conn.send(("[{}]".format(name) + msg).encode())

    else:
        print("Error!")

if __name__ == '__main__':
    main()