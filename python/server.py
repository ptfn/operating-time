import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('127.0.0.1', 55555))
print('Start Server')

while True:
    clients = []
    data, address = sock.recvfrom(1024)
    print(address[0], address[1])

    if address not in clients:
        if not clients:
            for client in clients:
                sock.send(address, client)  # Correct Data Forwarding
            sock.send(clients, address)     # Her
        clients.append(address)
