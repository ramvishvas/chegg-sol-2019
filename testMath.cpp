#include <iostream>
using namespace std;

int sum(int a, int b){
	return (a+b);
}

int diff(int a, int b){
	return (a > b? (a-b):(b-a));
}

int agv(int a, int b){
	return (a+b)/2;
}

int max(int a, int b){
	return (a > b? a:b);
}

int min(int a, int b){
	return (a > b? b:a);
}

int main()
{
	int a,b;
	cout<<"Please enter the two numbers: ";
	cin>>a>>b;

	cout<<"The numbers entered are "<<a<<" and "<<b<<"."<<endl;
	cout<<"The sum of "<<a<<" and "<<b<<" is: "<<sum(a,b)<<endl;
	cout<<"The difference of "<<a<<" and "<<b<<" is: "<<diff(a,b)<<endl;
	cout<<"The average of "<<a<<" and "<<b<<" is: "<<agv(a,b)<<endl;
	cout<<"The maximum of "<<a<<" and "<<b<<" is: "<<max(a,b)<<endl;
	cout<<"The minimum of "<<a<<" and "<<b<<" is: "<<min(a,b)<<endl;
	
	return 0;
}
