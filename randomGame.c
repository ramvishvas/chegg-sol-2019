#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Generates numbers in range [lower, upper]. 
int getRandomInt(int lower, int upper) 
{ 
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

int main() 
{ 
	int num1, num2, selectedNum;
	char choice = 'y';
    // Use current time as seed for random generator 
	srand(time(0)); 

	do 
	{
		printf("Tell me, what is the sum of the following integers?\n");

		num1 = getRandomInt(1, 100);
		printf("    %d\n",num1);

		num2 = getRandomInt(1, 100);
		printf("+   %d\n",num2);
		printf("-------\n");

		scanf("%d", &selectedNum);
		if(num1 + num2 == selectedNum) 
		{
			printf("*** Correct! %d + %d = %d\n",num1, num2, (num1 + num2));
		} 
		else 
		{
			printf("--- Incorrect :( %d + %d = %d\n",num1, num2, (num1 + num2));
		}

		printf("Play again (Y/N)\n");
		getchar();
		scanf("%c",&choice);

	} while(choice == 'y' || choice == 'Y');

	return 0; 
} 