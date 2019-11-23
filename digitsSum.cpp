#include <iostream>
using namespace std;
const int MAXNAME = 10;

int main()
{
    int pos;
    char* name;
    int* one;
    int* two;
    int* three;
    int result;
    
    one = new int;
    two = new int;
    three = new int;
    name = new char;

    cout << "Enter your last name with exactly 10 characters." << endl;
    cout << "If your name has < 10 characters, repeat last letter. " << endl
         << "Blanks at the end do not count." << endl;

    for (pos = 0; pos < MAXNAME; pos++)
        cin >> *(name+pos);       // read a character into the name array                   
        cout << "Hi ";


    for (pos = 0; pos < MAXNAME; pos++)
        cout << *(name+pos);   // print a character from the name array    

    cout << endl << "Enter three integer numbers separated by blanks" << endl;
    cin >> *one >> *two >> *three;

    cout << "The three numbers are " << endl;
    cout << *one << "|" << *two << "|" << *three << endl;// output those numbers

    // here you have divided third number by 3
    result = *one + *two + *three;// calculate the sum of the three numbers

    cout << "The sum of the three values is " << result << endl;

    delete one;//code to deallocate one, two, three and name
    delete two;
    delete three;
    delete name;
    return 0;
}