#include <stdio.h>
#include <stdlib.h>
void printPattern(int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = -(n-1); j < n; ++j)
		{
			if(i == n-1){
				printf("*");
			}
			else if (i == abs(j))
			{
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main()
{
	int n;

	printf("Enter n: ");
	scanf("%d", &n);

	printPattern(n);

	return 0;
}