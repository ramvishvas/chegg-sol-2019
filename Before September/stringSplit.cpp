#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	// to store input paragraph
	string paragraph;
	// to store the final word
	vector<string> wordArray;
	// to store temp word
	string word = "";

	// take input
	cout<<"Enter your string : ";
	cin>>paragraph;

	// scan entire input
	for (int i = 0; i < paragraph.length(); ++i)
	{
		// if comma found
		if (paragraph[i] == ',')
		{
			// if word is not empty
			if (word != "")
			{
				// store word and reset it to empty
				wordArray.push_back(word);
				word = "";
			}
		} else {
			// else add new character to word
			word += paragraph[i];
		}
	}
	// for final word -> when no comma at end of paragraph
	if (word != "")
	{
		wordArray.push_back(word);
		word = "";
	}
	
	// print stored word
	cout<<"Output: { ";
	for (int i = 0; i < wordArray.size(); i++) {
        cout<<wordArray[i]<<" ";
	}
	cout<<"}"<<endl;
	return 0;
}