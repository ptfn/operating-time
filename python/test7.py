import logging

logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    filename='example.log',
    filemode='w',
    level=logging.DEBUG,
    )
logging.debug('This message should go to the log file')
logging.info('So should this')
logging.warning('And this, too')