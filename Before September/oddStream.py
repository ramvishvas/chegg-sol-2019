import random

def oddStream(stream):
	# consider empty list
	myList= []
	for num in stream:
		# if number is odd
		if num % 2 != 0:
			# appent that number to list
			myList.append(num)
	# return odd number list
	return myList

def testoddStream():
	# consider empty list
	l = []
	for i in range(100):
		# add random list in l
		l.append(random.randint(1,101))
	# prin require odd list
	print('Original List: ', l)
	print()
	print('OddNumer List: ', oddStream(l))

testoddStream()