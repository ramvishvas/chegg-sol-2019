# total data in bit
data = 4.625 * (1000 *1000 * 1000) * 8

# download speed in bit per second
speed = 25 * (1000 * 1000)

# total time in second
total_time = data / speed

# get minuts
minute = int(total_time // 60)

#get seconds
second = int(total_time % 60)

#print time
print("Total time is:",minute,'minuts and',second,'seconds')