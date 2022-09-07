import schedule


def hello():
    print(1/0)


def main():
    schedule.every(5).seconds.do(hello)
    while True:
        try:
            schedule.run_pending()
        except Exception as e:
            print(e)
            break


if __name__ == "__main__":
    main()
