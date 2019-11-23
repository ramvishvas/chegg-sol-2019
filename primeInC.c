#include <stdio.h>
int isPrime(int number) 
{
	int i;
	int halfNumber = number / 2;
	if (number % 2 == 0)
	{
		return 0;
	}

	for (int i = 3; i < halfNumber; ++i)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int data[] = {28,81,13,31,54,7,31,19,23,40,39,15,69,50,41,33,3,5,8};
	// assume all are not prime
	// 0 means not prime and 1 means prime
	int status[20] = {0};
	int size = 20;

	for (int i = 0; i < size; ++i)
	{
		if(isPrime(data[i]))
		{
			status[i] = 1;
		}
	}

	for (int i = 0; i < size; ++i)
	{
		if(status[i])
		{
			printf("%d\t: Prime\n",data[i]);
		}
		else
		{
			printf("%d\t: Not Prime\n",data[i]);
		}
	}

	return 0;
}