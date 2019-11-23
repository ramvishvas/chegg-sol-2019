#include <iostream>
#include <string> 
using namespace std;
int main()
{
	int n, temp;
	cout<<"Inter your Number: ";
	cin>>n;

	temp = n;
	// to get last 3 digit
	for(int i = 1; i <= 3; i++) 
	{
		int digit = temp % 10;
		temp = temp / 10;
		cout<<"10^"<<(i-1)<<"  digit\t\t: "<<digit<<endl;
	}

	// convert number to string
	string number = to_string(n);
	
	// get required number from beggning
	if(number[2] && number[3] && number[4]) 
	{
		cout<<"col 3,4,5 number\t: "<<number[2]<<number[3]<<number[4]<<endl;
	} 

	else if(number[2] && number[3])
	{
		cout<<"col 3,4,5 number\t: "<<number[2]<<number[3]<<",3rd NotExist"<<endl;
	} 

	else  if(number[2])
	{
		cout<<"col 3,4,5 number\t: "<<number[2]<<",2nd and 3rd NotExist"<<endl;
	} 

	else {
		cout<<"col 3,4,5 number\t: NotExist"<<endl;
	}

	return 0;
}