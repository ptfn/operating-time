import threading
import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


def read_sock(sock):
    while 1:
        data = sock.recv(1024)
        if not data:
            break
        print(data.decode('utf-8'))


def main():
    server = '127.0.0.1', 55553
    sock.connect(server)
    sock.sendto(('Connect to server').encode('utf-8'), server)

    thread = threading.Thread(target=read_sock, args=[sock])
    thread.start()

    while True:
        try:
            message = input()
            sock.sendto(('['+alias+']'+message).encode('utf-8'), server)
        except KeyboardInterrupt:
            print("Exit")
            exit(0)


if __name__ == "__main__":
    main()
