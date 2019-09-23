def truth_value(integer):
	"""Convert an integer into a truth value."""
	# Convert 0 into False and all other integers,
	# including 1, into True
	if integer == 0:
		truth_value = False
	else:
		truth_value = True

	return truth_value


def integer_0_or_1(truth_value):
	"""Convert a truth value into 0 or 1."""
	# Convert True into 1 and False
	# into 0
	if truth_value == True:
		integer = 1
	else:
		integer = 0

	return integer

def and_binary(a, b):
	A = truth_value(a);
	B = truth_value(b);
	# according to the question we should do the logical and of given value
	result = integer_0_or_1(A) and integer_0_or_1(b);
	return result

print(and_binary(0, 0))
print(and_binary(0, 1))
print(and_binary(1, 0))
print(and_binary(1, 1))
