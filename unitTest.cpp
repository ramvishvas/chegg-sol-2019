#include <iostream>
using namespace std;
int CubeNum(int origNum) {
	return origNum * origNum * origNum;
}
int main()
{
	cout<<"Testing started"<<endl;

	cout<<"2, excepting 8, got: "<<CubeNum(2)<<endl;

	// this is  for 3
	cout<<"3, excepting 27, got: "<<CubeNum(3)<<endl;

	// this is for -1
	cout<<"-1, excepting -1, got: "<<CubeNum(-1)<<endl;

	cout<<"Testing completed"<<endl;
	
	return 0;
}