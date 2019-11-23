#include <stdio.h>
#include <stdlib.h>
int compute(int n, int a1, int a2){
	if (n <= 1)
	{
		return a1;
	}
	else if (n <= 2)
	{
		return a2;
	}
	else
	{
		int sum = 0;
		for (int i = n - 1; i >= 1; --i)
		{
			sum += compute(i, a1, a2);
		}
		return sum;
	}
}

int main()
{
	int n, a1, a2;

	printf("Enter a1: ");
	scanf("%d", &a1);

	printf("Enter a2: ");
	scanf("%d", &a2);

	printf("Enter n: ");
	scanf("%d", &n);

	int tn = compute(n,a1,a2);

	printf("Value: %d\n",tn);
	return 0;
}