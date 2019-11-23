#include <stdio.h>

int sum(int x, int y, int z)
{
	return x+y+z;
}


int average(int x, int y, int z)
{
	return (x+y+z)/3;
}

int product(int x, int y, int z)
{
	return (x*y*z);
}


int largest(int x, int y, int z)
{
	if(x > y && x > z)
	{
		return x;
	} 
	else if(y > z)
	{
		return y;
	}
	else
	{
		return z;
	}
}

int smallest(int x, int y, int z){
	if(x < y && x < z)
	{
		return x;
	} 
	else if(y < z)
	{
		return y;
	}
	else
	{
		return z;
	}
}


int main()
{
	int x, y, z;

	printf("Enter 1st Integer: ");
	scanf("%d", &x);

	printf("Enter 2nd Integer: ");
	scanf("%d", &y);

	printf("Enter 3rd Integer: ");
	scanf("%d", &z);

	printf("\nEntered Number: %d, %d, %d\n",x,y,z);

	printf("\nSUM\t: %d\n",sum(x,y,z));
	printf("AVERAGE\t: %d\n",average(x,y,z));
	printf("Product\t: %d\n",product(x,y,z));
	printf("SMALLEST: %d\n",smallest(x,y,z));
	printf("LARGEST\t: %d\n",largest(x,y,z));

	return 0;
}