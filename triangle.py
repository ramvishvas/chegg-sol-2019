x=int(input('Enter an Interger : '))
for i in range(x-1,-1,-1):
	for j in range(x-1,-x,-1):
		if i == abs(j):
			print('*',end='')
		else:
			print(end=' ')
	print()
