import os
import sys

update = "sudo apt update"
python = "sudo apt -y install python3.9"
requests = "pip3 install -r {}".format(sys.argv[1])
commands = [update, python, requests]

for i in range(len(commands)):
    os.system(commands[i])

# system, git, gpg and etc.