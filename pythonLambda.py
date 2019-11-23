# part 1
cube = lambda x: x*x*x

print('cube(2): ', cube(2))
print('cube(3): ', cube(3))
print('cube(8): ', cube(8))

# part 2
def decrement_list(lst):
	return list(map(lambda x: x - 1, lst))

print()
print('decrement_list([1, 2, 3]): ',decrement_list([1, 2, 3]))
print('decrement_list([20, 14, 13]): ',decrement_list([20, 14, 31]))


# part 3
def remove_negative(lst):
	return list(filter(lambda x: x >= 0, lst))

print()
print('remove_negative([-1, 3, 4, -99]): ',remove_negative([-1, 3, 4, -99]))
print('remove_negative([-7, 0, 1, 2, 3, 4, 5]): ',remove_negative([-7, 0, 1, 2, 3, 4, 5]))
print('remove_negative([50, 60, 70]): ',remove_negative([50, 60, 70]))


# part 4
def is_all_strings(lst):
	for s in lst:
		if not isinstance(s, str):
			return False

	return True

print()
print('is_all_strings(["a", "b", "c"]): ',is_all_strings(["a", "b", "c"]))
print('is_all_strings([2, "a", "b", "c"]): ',is_all_strings([2, "a", "b", "c"]))
print('is_all_strings(["hello", "goodbye"]): ',is_all_strings(["hello", "goodbye"]))

# part 4
def extremes(lst):
	return [min(lst), max(lst)]

print()
print('extremes([1,2,3,4,5]): ',extremes([1,2,3,4,5]))
print('extremes((99,25,30-7)): ',extremes((99,25,30,-7)))
print('extremes("alcatraz"): ',extremes("alcatraz"))