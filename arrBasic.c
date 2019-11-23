#include <stdio.h>
#define N 5
void reverse(int A[N], int size){
	int start = 0, end = size - 1;
	while(start < end)
	{
		int temp = A[start];
		A[start] = A[end];
		A[end] = temp;
		++start;
		--end;
	}
}

float getLargest(float arr[], int size)
{
	// if invalid size
	if (size <= 0)
	{
		reverse -1;
	}
	else
	{
		// consider 1st as largest
		float max = arr[0];
		for (int i = 1; i < size; ++i)
		{
			// if new larest fount then update it
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}
}


float getSmallest(float arr[], int size)
{
	// if invalid size
	if (size <= 0)
	{
		reverse -1;
	}
	else
	{
		// consider 1st as smallest
		float min = arr[0];
		for (int i = 1; i < size; ++i)
		{
			// if new smallest fount then update it
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}
}


int main()
{
	// part 1
	int A[N] = {3,5,7,9,11};
	reverse(A, N);
	printf("Part One Reversed Array: ");
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n\n");

	// part 2
	printf("This is Part 2\n\n");
	int size = 10;
	float array[size], temp;
	// take input
	for (int i = 0; i < size; ++i)
	{
		printf("Enter a number between (1 - 100) : ");
		scanf("%f", &temp);
		if(temp >=1 && temp <= 100)
		{
			array[i] = temp;
		}
		else
		{
			printf("Invalid Number\n");
			--i;
		}
	}

	// print taken number
	printf("\nArray is: ");
	for (int i = 0; i < size; ++i)
	{
		printf("%0.2f ",array[i]);
	}
	printf("\n\n");

	float l = getLargest(array, size);
	float s = getSmallest(array, size);

	printf("Largest : %0.2f",l);
	printf("\nSmallest: %0.2f",s);
	printf("\n");

	return 0;
}