import socket
import sys

link = str(sys.argv[1])
key = str(sys.argv[2])

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('0.0.0.0', 8889))
sock.listen()
conn, addr = sock.accept()

conn.send("Чтобы тебя проверить ответить на 3 вопроса которые знает только Марик!\n".encode("utf8"))

while True:
    win = 0

    conn.send("1) Лучшая операционная система:\n".encode("utf8"))
    data = conn.recv(1024).decode("utf8")
    if data == "GNU/Linux\n" or data == "Linux\n" or data == "linux\n" or data == "gnu/linux\n":
        win += 1

    conn.send("2) Лучший язык программирования:\n".encode("utf8"))
    data = conn.recv(1024).decode("utf8")
    if data == "Rust\n" or data == "rust\n":
        win += 1

    conn.send("3) Самая лучшая криптовалюта:\n".encode("utf8"))
    data = conn.recv(1024).decode("utf8")
    if data == "Monero\n" or data == "monero\n":
        win += 1

    if win == 3:
        conn.send(f"\nОчень хорошо это ты. Вот держи ключ и ссылку.\nСсылка: {link}\nКлюч: {key}\n".encode("utf8"))
        break
    else:
        conn.send("Кажись это не ты, пройди ещё раз.\n".encode("utf8"))
