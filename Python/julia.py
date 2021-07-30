import pygame
import os

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

pygame.init()

W = 1200
H = 600

sc = pygame.display.set_mode((W, H))
pygame.display.set_caption("Множества Жюлиа")
sc.fill(WHITE)

FPS = 30
clock = pygame.time.Clock()

# ---  Числа для разных форм множеств Жюлиа  --------------
c = complex(-1)
#c = complex(-0.2, 0.75)
#c = complex(-0.1244, 0.756)
#c = complex(-0.1194, 0.6289)
#c = complex(-0.7382, 0.0827)
# c = complex(0.377, -0.248)
# ---------------------------------------------------------

P = 200                     # размер [2*P+1 x 2*P+1]
scale = P / 0.25               # масштабный коэффициент
view = (0, -500)            # координаты смещения угла обзора
n_iter = 100                # число итераций для проверки принадлежности к множеству Жюлиа

for y in range(-P+view[1], P+view[1]):
    for x in range(-P+view[0], P+view[0]):
        a = x / scale
        b = y / scale
        z = complex(a, b)
        n = 0
        for n in range(n_iter):
            z = z**2 + c
            if abs(z) > 2:
                break

        if n == n_iter-1:
            r = g = b = 0
        else:
            r = (n % 2) * 32 + 128
            g = (n % 4) * 64
            b = (n % 2) * 16 + 128

        pygame.draw.circle(sc, (r, g, b), (x + P - view[0], y + P - view[1]), 0)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

    pygame.display.update()
    clock.tick(FPS)