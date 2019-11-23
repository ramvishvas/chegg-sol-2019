#include <iostream>
using namespace std;

void partOne()
{
	int max = 0, num;

	cout<<"Enter 5 grades: ";

	for (int i = 1; i <= 5; ++i)
	{
		cin>>num;

		if (i == 1)
		{
			max = num;
		}
		else if (num > max)
		{
			max = num;
		}
	}

	cout<<"The maximum is "<< max<<endl;
}

void partTwo()
{
	int max = 0, num;

	cout<<"Enter the grades (Enter -1 if done): ";

	while(1)
	{
		cin>>num;

		if (num == -1)
		{
			break;
		}
		else if (num > max)
		{
			max = num;
		}
	}

	cout<<"The maximum is "<< max<<endl;
}

void partThree()
{
	int sum, numberOfRepetations, num;

	cout<<"Enter numberOfRepetations: ";
	cin>>numberOfRepetations;

	for (int i = 1; i <= numberOfRepetations; ++i)
	{
		cout<<"Enter a number: ";
		cin>>num;
		sum = 0;
		for (int j = 1; j <= num; ++j)
		{
			sum += j;
		}
		cout<<"The sum of 1 to "<<num<<" is "<<sum<<endl<<endl;
	}
}

int main()
{
	partOne();
	cout<<endl;

	partTwo();
	cout<<endl;

	partThree();
	return 0;
}