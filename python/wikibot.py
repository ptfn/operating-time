import telebot, wikipedia, time, os

bot = telebot.TeleBot(token=os.getenv('TOKEN'))

def getwiki(text):
    try:
        wikipedia.set_lang("ru")
        ny = wikipedia.page(text[6:])
        return ny.url
    
    except Exception as e:
        try:
            wikipedia.set_lang("eu")
            ny = wikipedia.page(text[6:])
            return ny.url
        
        except Exception as e:
            return "Article not found!"

def getcont(text):
    try:
        wikipedia.set_lang("ru")
        ny = wikipedia.page(text[9:])
        string = ny.content
        return string[:string.find("\n")]
    
    except Exception as e:
        return "Content not found!"

@bot.message_handler(commands=["start"])
def start(message):
    bot.send_message(message.chat.id, "Hello, i am wikibot.")

@bot.message_handler(commands=["find"])
def handle_page(message):
    bot.send_message(message.chat.id, getwiki(message.text))

@bot.message_handler(commands=["content"])
def handle_cont(message):
    bot.send_message(message.chat.id, getcont(message.text))

def telegram_polling():
    try:
        bot.polling(none_stop=True, timeout=10)
    
    except:
        bot.stop_polling()
        time.sleep(5)
        telegram_polling()

if __name__ == "__main__":
    telegram_polling()