import telebot, wikipedia, time

bot = telebot.TeleBot("2096368590:AAGDcAGZ_zJ9tZnOB5zyUC2OQopmas5W05I")
wikipedia.set_lang("ru")

def getwiki(text):
    try:
        ny = wikipedia.page(text[6:])
        return ny.url
    except Exception as e:
        return "Article not found!"

@bot.message_handler(commands=["start"])
def start(message):
    bot.send_message(message.chat.id, "Hello, i am wikibot.")

@bot.message_handler(commands=["find"])
def handle_text(message):
    bot.send_message(message.chat.id, getwiki(message.text))

def telegram_polling():
    try:
        bot.polling(none_stop=True, timeout=60)
    except:
        bot.stop_polling()
        time.sleep(10)
        telegram_polling()

if __name__ == "__main__":
    telegram_polling()