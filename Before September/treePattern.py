def pattern(n):
	if n == 0:
		return
	# given algorith
	else:
		pattern(n-1)
		print(n,'******'*n)
		pattern(n-1)

try:
	# take input and convert it into integer
	n = int(input("Enter the number of branches: "))
	# if number is pisitive
	if n > 0:
		pattern(n)
	# if number is negative
	else:
		print("Only positive number allowed")
# raise error message if input is not number
except Exception as e:
	print("Invalid input")
