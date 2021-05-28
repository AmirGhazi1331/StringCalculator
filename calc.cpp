#include "calc.h"

void calc::Getinput()
{
  cout<<"pls Enter your order :"<<endl;
  string input; // Get Order from user 
  getline(cin,input);
  string temp[3];//Extract first & second String and operator 
  string word;
  int i=0;
  stringstream ss(input);
  while (ss >> word)
  {
      temp[i]=word;
      i++;
  }
  cout<<temp[0]<<endl;
  cout<<temp[1]<<endl;
  cout<<temp[2]<<endl;
}
