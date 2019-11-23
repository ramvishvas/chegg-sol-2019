#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int generate(){
	// reset to generate new number
	//srand(time(NULL)); 
	// generate number between 1 to 10000
	int number = ((rand() % 1000) + 1);
	return number;
}

int main()
{
	for (int i = 1; i <= 1000; ++i)
	{
		int num = generate();
		printf("%d  ",num);
	}
	printf("\n");
	return 0;
}