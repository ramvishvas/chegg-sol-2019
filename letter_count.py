def letter_count(string):
	count = {}
	for i in range(len(string)):
		char = string[i]
		if char == ' ':
			continue
		elif count.get(char):
			count[char] += 1
		else:
			count[char] = 1

	return count

string = input('Enter string: ')
ans_dict = letter_count(string)
for k, v in ans_dict.items():
	print(k, ',', v)