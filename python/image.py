from PIL import Image


def image(num):
    rare = [3442, 910, 846, 794, 377, 373, 300, 224, 220, 81, 57]
    try:
        bg = Image.open("img/bg.png")
        if num in rare:
            fg = Image.open("img/crypto/punk{}.png".format(num))
        else:
            fg = Image.open("img/punk{}.png".format(num))
    except FileNotFoundError:
        print("Файл не найден!")

    size = (500, 500)
    saved = "save.png"

    fgr = fg.resize(size).convert("RGBA")
    bgr = bg.resize(size).convert("RGB")

    bgr.paste(fgr, None, fgr)
    bgr.save(saved)


image(0)
