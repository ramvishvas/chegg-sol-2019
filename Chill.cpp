#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int random_integer;
	srand(9);

	for(int index=0; index<30; index++)
	{
		random_integer = (rand()%100)+1;
		cout << random_integer << endl;
	}
	return 0;
}

