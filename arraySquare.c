#include <stdio.h>

void display(int start, int end)
{
	if(start > end)
	{
		return;
	}
	else
	{
		printf("%d - %d\n",start, start*start);
		display(start+1, end);
	}
}

int main()
{
	int num;
	printf("Enter first number of array: ");
	scanf("%d", &num);
	display(1, num);
	return 0;
}