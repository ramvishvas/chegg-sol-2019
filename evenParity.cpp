#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    char c;
    
    int bitCounts, pBit;;
    cout<<"Enter one letter among(A, Z, D, a): ";
    while (cin>>c){     //ctrl-Z to stop
       bitset<8> bs(c);
       // cout<<"bs: "<<bs<<endl;

       bitCounts = bs.count(); 
       // cout<<"bitCounts: "<<bitCounts<<endl;

       pBit = bitCounts % 2? 0: 1;
       cout<<"Even Parity bit: "<<pBit<<endl;

       cout<<"\nEnter one letter among(A, Z, D, a): ";
    }
    
}
