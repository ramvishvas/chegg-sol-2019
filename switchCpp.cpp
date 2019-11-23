#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int Enter = 10;
	cin>>Enter;

	switch(Enter)
	{
		case 1: Enter = -4;
		case 2: Enter = -6;
		case 4: break;
		case 6: Enter = -8;
		break;
		default: Enter = -1;
	}

	cout<<"Enter Is: "<<Enter<<endl;
	return 0;
}

/*
Note: whenever a case is matched that case and all case below that will 
excute, it will stop only if a 'break' statement is present.
whenever it found a 'break' it will not excute the case which is below statement 'break'
*/