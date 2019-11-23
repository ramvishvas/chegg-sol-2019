#include <iostream>
void sort (int x[], int size);
using namespace std;
int main ()
{
    const int size = 20; 
    int a[size];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    cout << "\nBefore Sort  " << a[0] << " " << a[1] << " " << a[2] << endl;

    sort (a, 3);
    
    cout << "\nAfter Sort  " << a[0] << " " << a[1] << " " << a[2] << endl;
    
    a[0] = 3;
    a[1] = 2;
    a[2] = 1;
    
    cout << "\nBefore Sort  " << a[0] << " " << a[1] << " " << a[2] << endl;
    
    sort (a, 3);
    
    cout << "\nAfter Sort  " << a[0] << " " << a[1] << " " << a[2] << endl;
    
    a[0] = 20;
    a[1] = 30;
    a[2] = -50;
    
    cout << "\nBefore Sort  " << a[0] << " " << a[1] << " " << a[2] << endl;
    
    sort (a, 3);
    
    cout << "\nAfter Sort  " << a[0] << " " << a[1] << " " << a[2] << endl;
    
}
int temp;
void sort (int x[], int size)
{
    bool switch_on = true; // a[] is not sorted 
    while (switch_on) 
    {
        // set the switch correctly:
        switch_on = true;       

        for (int i = 0; i <= size - 2; i++) 
        {
            if (x[i] > x[i + 1])
            {  
                //interchange values and set switch_on correctly;
                x[i] = x[i] + x[i+1];
                x[i+1] = x[i] - x[i+1];
                x[i] = x[i] - x[i+1];
            }

            if ( i == size - 2)
            {
                switch_on = true;
            }
        }
    }
}