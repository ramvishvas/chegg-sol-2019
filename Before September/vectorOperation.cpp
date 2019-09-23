#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> oldData(3);
  vector<int> newData(4);
  unsigned int i = 0;

  oldData.at(0) = 10;
  oldData.at(1) = 12;
  oldData.at(2) = 18;
  // oldData.resize(4);
  // oldData.at(0) = 25;
  // oldData.at(1) = 27;
  // oldData.at(2) = 29;
  // oldData.at(3) = 23;

  newData.at(0) = 25;
  newData.at(1) = 27;
  newData.at(2) = 29;
  newData.at(3) = 23;

  // check is size same for both vector
  if (oldData.size() == newData.size())
  {
    // consider bothe vector is same
    bool isSame = true;
    for (i = 0; i < newData.size(); ++i) {
      // if data did not match then
      // update oldData vector and set isSame to false
      if(oldData.at(i) != newData.at(i)){
        oldData[i] = newData.at(i);
        isSame = false;
      }
    }
    // check isSame is true or not
    if (isSame)
    {
      printf("Data matches!\n");
    }
  }
  else 
  {
    // resize oldData vector
    oldData.resize(newData.size());
    for (i = 0; i < newData.size(); ++i) {
      oldData[i] = newData.at(i);
    }
  }
   
  for (i = 0; i < oldData.size(); ++i) {
    cout << oldData.at(i) << " ";
  }
  cout << endl;
  return 0;
}