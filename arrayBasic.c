#include <stdio.h>
#define N 3
void requiredFunction(int A[N], int B[N][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N ; ++j)
		{
			int sum = 0;
			// add all from A[i] to A[j]
			for (int k = i; k <= j; ++k)
			{
				sum += A[k];
			}
			B[i][j] = sum;
		}
	}
}
int main()
{
	int A[N] = {1,2,3};
	// initilize to 0
	int B[N][N] = {0};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}

	requiredFunction(A, B);

	printf("\n");

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}

	return 0;
}