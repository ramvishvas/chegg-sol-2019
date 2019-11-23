sum = 0
count = 0
while True:
	# print("%.3f" % sum)
	if count % 50 == 0:
		print("%.3f" % sum)
	if sum >= 1:
		break;
	else:
		sum = sum + 0.001
		count += 1