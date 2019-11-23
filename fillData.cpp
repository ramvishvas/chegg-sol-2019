#include <iostream>
using namespace std;


int generateRandomNumber(int min, int max) 
{
	return min + rand() % (( max + 1 ) - min);
}

void fillArray(int data[], int size, int min, int max)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		int num = generateRandomNumber(min, max);
		data[i] = num;
	}
}


int main(int argc, char const *argv[])
{
	int size, min, max;

	cout<<"Enter size: ";
	cin>>size;
	int data[size];

	cout<<"Enter min: ";
	cin>>min;
	cout<<"Enter max: ";
	cin>>max;

	fillArray(data, size, min, max);

	cout<<"\nData Array: ";
	for (int i = 0; i < size; ++i)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;

	return 0;
}