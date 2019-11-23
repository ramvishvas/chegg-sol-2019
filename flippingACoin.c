#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(int argc, char const *argv[])
{
	int totalFlip = 0, matchCount = 0;
	int previousNumber = -2, currentNumber = -1;
	// to reset random generation
	srand(time(0)); 
	printf("Number Generated: ");
	while(matchCount != 3)
	{	
		// temp will either be 0 or 1
		currentNumber = rand() % 2;
		printf("%d  ",currentNumber);
		// check if match found
		if (currentNumber == previousNumber)
		{
			matchCount += 1;
		}
		// if mathch not found
		else 
		{
			previousNumber = currentNumber;
			matchCount = 1;
		}
		totalFlip += 1;
	}
	printf("\ntotalFlip: %d\n", totalFlip);
	return 0;
} 