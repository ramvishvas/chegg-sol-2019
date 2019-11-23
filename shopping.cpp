#include <iostream>
using namespace std;
int main()
{
	float n, temp, totalPrize = 0;
	cout<<"Enter the number of items ordered: ";
	cin>>n;

	for (int i = 1; i <= n; ++i)
	{
		cout<<"Enter the price of item no. "<<i<<": ";
		cin>>temp;

		totalPrize = totalPrize + temp;
	}

	if (totalPrize >= 200)
	{
		cout<<"The shipping and handling fee is: $0.00"<<endl;
		cout<<"The billing amount is: $"<<totalPrize<<endl;
	} else {
		float shippingAndHandlingFee = n * 10;
		totalPrize = totalPrize + shippingAndHandlingFee;

		cout<<"The shipping and handling fee is: $"<<shippingAndHandlingFee<<endl;
		cout<<"The billing amount is: $"<<totalPrize+n<<endl;
	}

	return 0;
}