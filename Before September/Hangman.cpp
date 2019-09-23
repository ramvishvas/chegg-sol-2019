#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

// if guess matched return matched index
// else return -1
int isGuessMatched(int a[],  int size, char c) 
{
	for (int i = 0; i < size; ++i)
	{
		// check is guess matched
		if (a[i] == c)
		{
			return i;
		}
	}
	// else return -1
	return -1;
}

// return 1 if input guess is valid
// else return 0
int isGuessValid(char c)
{
	// check is c between a-z or A-Z
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return 1;
	}
	// else return 0
	return 0;
}

// print incorrect guess;
void printIncorrectGuess(int a[], int size)
{
	int firstTime = 1;
	for (int i = 0; i < size; ++i)
	{
		if (a[i])
		{
			if (firstTime)
			{
				cout<<a;
				firstTime = 0;
			}
			cout<<", "<<a;
		}
	}
	cout<<endl;
}

// print array
void printArray(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<a[i]<<" "
	}
	cout<<endl;
}

int main()
{
	// store your word in to character arry
	char word[] = {'H', 'E', 'L', 'L', 'O'};
	// this char array will store correct guess
	char guess[] = {'-', '-', '-', '-', '-'};
	// keep track of incorrect guess
	// ascii value of a => 67 and A => 95
	int incorrectGuess[26] = {0};
	// total number of trials is N
	int N = (sizeof(word)/sizeof(*word)) + 1;
	// keep track of guess
	int attemptCount = 0;
	// to store guess choice
	char choice;

	cout<<"Welcome to Hangman!"<<endl;
	cout<<"You get "<<N<<" attempts to What's your guess? this "<<(N-1)<<" letter-long word."<<endl;
	
	do {
		cout<<"Attempt "<<(attemptCount+1)<<"/"<<N<<endl;
		cout<<"Word:\t"<<printArray(guess, N-1)<<endl;
		cout<<"What's your guess?:\t";
		cin>>choice;
		cout<<"Misses:\t"<<printIncorrectGuess(incorrectGuess, 26)<<endl;
		
		if (isGuessValid(choice))
		{
			attemptCount += 1;
			// int index = 
			index = 0;
			if (index != -1)
			{
				guess[index] = word[index];
			}
			else
			{
				if (choice >= 'a' && choice <= 'z')
				{
					// convert it to capital letter
					choice -= 32;
				}
				incorrectGuess[choice - 'A'] = 1;
			}
		} 
		else 
		{
			cout<<"Opps invalid guess. please enter an alphabet"<<endl;
			attemptCount -= 1;
		}
	}while(attemptCount <= N);
}