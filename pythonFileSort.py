name = input("Enter filename: ")
try:
	with open(name) as f:
		data = list(set(f.read().strip().split()));
		data.sort();
		print(data)

except FileNotFoundError as e:
	print(e)
