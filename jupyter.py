# part 1
print("Part 1")
x = 0
while(x <= 10):
	if x == 3 or x == 6:
		x += 1
		continue
	else:
		print(x)
		x += 1

#part 2
print("\nPart 2")
sum = 0
while True:
	num = int(input("Enter an Integer(0 to exit): "))
	if num == 0:
		break
	else:
		sum += num;
print(sum)

# for jupyter please copy the code and paste it in jupyter shell
# and then click the run button from shell menu
# NOTE : please maintain the indentation of code when you paste it