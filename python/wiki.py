import wikipedia as wiki
import sys

def main():
    wiki.set_lang("ru")
    articles = sys.argv[1:]

    for idx, article in enumerate(articles):
        try:
            name = article.title()
            title = wiki.page(article)
            
            file = open(f"{article}.txt", "+a")
            file.write(title.content)
            file.close()
            print(f"{name}\t\033[32mfound\033[0m")

        except:
            print(f"{name}\t\033[31mnot\033[0m")

if __name__ == "__main__":
    main()
