#include <iostream>
using namespace std;
void sort(double *arr, int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; ++i)
	{
		// consider min element is at index min
		min = i;
		for (int j = i + 1; j < size; ++j)
		{
			// updete index of minimum number
			if (*(arr + j) < *(arr + min))
			{
				min = j;
			}
		}
		// swap min number with i index number
		temp = *(arr + i);
        *(arr + i) = *(arr + min);
        *(arr + min) = temp;
	}
}

bool isSorted(double *arr, int lower, int higher)
{
	// check index
	if (lower > higher)
	{
		return false;
	}
	// scan array and check is it sorted
	for (int i = lower; i < higher; ++i)
	{
		// if not sorted return false
		if (*(arr+lower) > *(arr + lower + 1))
		{
			return false;
		}
	}
	// esle return true
	return true;
}

void swapIfSmaller(double *arr, int lower, int higher)
{
	// check id lower index elem
	if (*(arr+lower) > *(arr + higher))
	{
		double temp = *(arr+lower);
		*(arr+lower) = *(arr + higher);
		*(arr + higher) = temp;
	}

}
int main(int argc, char const *argv[])
{
	double arr[] = { 10, 20, 30, 40, 50, 60, 70 };
	double arr2[] = { 90, 80, 70, 60, 50, 40, 30 };
	// if true 1 will be output else 0
	cout<<"IS SORTED: "<<isSorted(arr, 3, 5)<<endl;
	cout<<"IS SORTED: "<<isSorted(arr2, 3, 5)<<endl;

	swapIfSmaller(arr, 3, 5);
	for (int i = 0; i < 7; ++i)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	swapIfSmaller(arr2, 3, 5);
	for (int i = 0; i < 7; ++i)
	{
		cout<<arr2[i]<<"  ";
	}	
	cout<<endl;
	sort(arr2, 7);
	for (int i = 0; i < 7; ++i)
	{
		cout<<arr2[i]<<"  ";
	}	
	cout<<endl;
	return 0;
}