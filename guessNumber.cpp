#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int lower = 1;
	int upper = 100;
	int validGuess= 1;
	int invalidGuess =  0;
	int temp;
	/*
	int range = max - min + 1;
	int NUMBER = rand() % range + min;
	*/
	srand( time(NULL) );
	int NUMBER = (rand() % ( 100 )) + 1;
	// printf("%d\n",NUMBER ); 

	while(1)
	{
		cout<<"Guess "<<validGuess<<": Enter a number between "<<lower<<" and "<<upper<<" >> ";
		cin>>temp;
		if (temp >= lower && temp <= upper)
		{
			if (temp == NUMBER)
			{
				cout<<temp<<" is correct"<<endl;
				cout<<"It took you "<<validGuess<<" valid guess to find that number"<<endl;
				cout<<"You had "<<invalidGuess<<" out of range guess"<<endl;
				break;
			}
			else if (NUMBER > temp)
			{
				cout<<temp<<" is too low"<<endl;
				lower = temp + 1;
			}
			else
			{
				cout<<temp<<" is too high"<<endl;
				upper = temp - 1;
			}
			validGuess += 1;
		}
		else
		{
			cout<<temp<<" is not between "<<lower<<" and "<<upper<<endl;
			invalidGuess += 1;
		}
	}
	return 0;
}