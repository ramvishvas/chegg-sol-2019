#include <iostream>
using namespace std;

int calculateCost(float arr[], float cost, int currentIndex, int lastIndex){
	if (currentIndex == lastIndex)
	{
		return cost;
	}  else
	{
		if (currentIndex+1 = lastIndex)
		{
			/* code */
		}
	}
	return 
;}

int main()
{
	int size;
	cout<<"Enter size: ";
	cin>>size;

	float arr[size];
	arr[0] = 0;

	for (int i = 1; i < size; ++i)
	{
		cout<<"Enter the no. of column "<<i+1<<": ";
		cin>>arr[i];
	}

	cout<<"\nEntered Number: ";
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;

	cout<<"\nOutput: "<<calculateCost(arr, 0, 0, size-1)<<endl;

	return 0;
}