import matplotlib.pyplot as plt
import csv

data1 = []  # Low price
data2 = []  # High price
data3 = []  # Price
data4 = []  # Hashrate
data5 = []  # Difficulty

csv_rfile = open('/home/ptfn/Documents/Files/monero.csv', 'r')
csvreader = csv.reader(csv_rfile)

for row in csvreader:
    data1.append(row[2])
    data2.append(row[3])
    data3.append(row[1])
    data4.append(row[5])
    data5.append(row[6])

f = lambda arr: [float(arr[i]) for i in range(1, len(arr))]

# Converting
data1 = f(data1)
data2 = f(data2)
data3 = f(data3)
data4 = f(data4)
data5 = f(data5)

fig, axs = plt.subplots(3)
fig.suptitle('Monero Statistics')

# Price
axs[0].plot(data1[1:])
axs[0].plot(data2[1:])
axs[0].plot(data3[1:])
axs[0].set_title('Price')

# Hashrate
axs[1].plot(data4[1:])
axs[1].set_title('Hashrate')

# Difficulty
axs[2].plot(data5[1:])
axs[2].set_title('Difficulty')

plt.show()
