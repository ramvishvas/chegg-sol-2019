#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout<<"Inter 3 Number: ";
	cin>>a>>b>>c;

	// if a is bigger number
	if( a > b && a > c){
		if(b > c) {
			cout<<a<<" "<<b<<" "<<c<<endl;
		} else {
			cout<<a<<" "<<c<<" "<<b<<endl;
		}
	}
	// else if b is bigger number
	else if(b > c){
		if(a > c) {
			cout<<b<<" "<<a<<" "<<c<<endl;
		} else {
			cout<<b<<" "<<c<<" "<<a<<endl;
		}
	}
	// if c is bigger
	else {
		if(a > b) {
			cout<<c<<" "<<a<<" "<<b<<endl;
		} else {
			cout<<c<<" "<<b<<" "<<a<<endl;
		}
	}

	return 0;
}