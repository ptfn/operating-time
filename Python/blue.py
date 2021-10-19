import bluetooth

devices = bluetooth.discover_devices(lookup_names=True)
if len(devices) == 0:
    print("Not Found!")
else:
    print("Found {} devices:".format(len(devices)))
    for addr, name in devices:
        print("{} - {}".format(addr, name))