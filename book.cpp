#include <iostream>
#include <string>

using namespace std;

int main() {

    struct Book {
        string Title;
        string Author;
        double Cost;
        int PubYear;

    };

    Book Book [5];

    for (int i = 0; i < 5 ; i++ ){
        cout << "Enter the title of book " << i +1 << ": " << endl;
        string Title;
        // this is the extra line where you are taking first word as input
        // cin >> Book[i].Title;
        getline(cin, Book[i].Title);


        cout << "Enter the author of book " << i+1  << ": " <<endl;
        string Author;
        // this is the extra line where you are taking first word as input
        // cin >> Book[i].Author;
        getline(cin, Book[i].Author);

        cout << "Enter the price of book " << i+1  << ": " <<endl;
        cin >> Book[i].Cost;
        cout << "Enter the year of publication for book " << i+1 << ": " << endl;
        cin>> Book[i].PubYear;
    }

    cout << "What book do you want information on?" << endl;
    int bookNum;
    cin >> bookNum;

    cout << "Title: " << Book[bookNum -1].Title << endl;
    cout << "Author: " << Book[bookNum -1].Author << endl;
    cout << "Price: " <<  Book[bookNum -1].Cost << endl;
    cout << "Year of Publication: " << Book[bookNum -1].PubYear << endl;



    return 0;
}