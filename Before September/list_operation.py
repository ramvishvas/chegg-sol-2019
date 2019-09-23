# this function is provided by you
def delete_item(shopping_list):
    number=int(input("Which number to delete: "))
    if number<1 or number>len(shopping_list):
        print("Invalid number\n")
    else:
        item=shopping_list.pop(number-1)
        print(item," was deleted\n")
    print()

# append neww item to the list
def add_item(shopping_list):
	item = input('Please enter the item: ')
	shopping_list.append(item)
	print(item, 'was added to the shopping list')

# display all list
def display_list(shopping_list):
	for i in range(len(shopping_list)):
		print(i+1,':', shopping_list[i])

# menu function
def display_menu():
	print('Welcome to the program!')
	print('1. Add an item')
	print('2. List all items')
	print('3. Delete an item')
	print('4. Exit')
	
# main function
def main():
	# initilize the list
	shopping_list = ['bananas', 'apples']
	# display the menu
	display_menu()
	while True:
		# get choice of user
		choice = int(input('Enter a menu option: '))
		if choice == 1:
			add_item(shopping_list)
		elif choice==2:
			display_list(shopping_list)
		elif choice==3:
			delete_item(shopping_list)
		elif choice==4:
			print('have a great day!')
			break;
		else :
			pass

if __name__ == "__main__":
	main()