from PIL import Image

#Сохранения
try:
    img = Image.open("punk.png")
    bg = Image.open("bg.png")
except FileNotFoundError:
    print("Файл не найден!")

# Параметры
size = (500, 500)
saved = "save.png"

# Изменения размера
img_rsz = img.resize(size)
bg_rsz = bg.resize(size)

# Сохранение и показ
bg_rsz.paste(img_rsz, None, img_rsz)
bg_rsz.save(saved)
