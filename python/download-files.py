import requests
import argparse


def file_name(url):
    return str(url.split('/')[-1].split('.')[0])


def download(url='', format_file='', output=''):
    try:
        response = requests.get(url=url, stream=True)
        name = file_name(url)

        with open(f'{output}{name}.{format_file}', 'wb') as file:
            for chunk in response.iter_content(chunk_size=1024 * 1024):
                if chunk:
                    file.write(chunk)

        if format_file == 'png' or format_file == 'jpg':
            return 'Picture successfully downloaded!'

        elif format_file == 'mp4' or format_file == 'gif':
            return 'Video successfully downloaded!'

        elif format_file == 'mp3' or format_file == 'wav':
            return 'Audio successfully downloaded!'

        else:
            return 'File successfully downloaded!'

    except Exception as error:
        return 'Upps... Check the URL please!'


def main():
    parser = argparse.ArgumentParser(description='Download')
    parser.add_argument('-u', '--url', nargs='*', dest='url', help='url file')
    parser.add_argument('-f', '--format', dest='format', help='format file')
    parser.add_argument('-o', '--output', dest='output', help='output file')
    args = parser.parse_args()

    urls = args.url
    output = args.output
    format_file = args.format

    for idx, url in enumerate(urls):
        if output is None:
            print(download(url, format_file))

        else:
            print(download(url, format_file, output))


if __name__ == '__main__':
    main()
