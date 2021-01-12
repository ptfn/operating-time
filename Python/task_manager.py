
import psutil as ps
from prettytable import PrettyTable

table = PrettyTable(["System", "Percent"])
table_disk = PrettyTable(["Disk", "MegaBytes"])
table_network = PrettyTable(["Network", "MegaBytes"])

memory = ps.virtual_memory()
disk = ps.disk_usage('/')
disk_rw = ps.disk_io_counters()
network = ps.net_io_counters()

cpu = ps.cpu_percent(interval=1)
mem = memory.percent
disk = disk.percent
rb = round(disk_rw.read_bytes / 1000 / 1000  )
wb = round(disk_rw.write_bytes / 1000 / 1000 )
bs = round(network.bytes_sent / 1000 / 1000 )
br = round(network.bytes_recv / 1000 / 1000 )

table.add_row(["CPU",'{} %'.format(cpu)])
table.add_row(["Memory",'{} %'.format(mem)])
table.add_row(["Disk",'{} %'.format(disk)])
print(table)

table_disk.add_row(["Read",'{} MB'.format(rb)])
table_disk.add_row(["Write",'{} MB'.format(wb)])
print(table_disk)

table_network.add_row(["Sent",'{} MB'.format(bs)])
table_network.add_row(["Received",'{} MB'.format(br)])
print(table_network)