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
  if(temp[1]=="+")//check operator and pass it to its function
  {
      Plus(temp[0],temp[2]);
  }
}

void calc::Plus(string First, string Second)
{
  string both = First + Second;
  sort(both.begin(), both.end());
  cout<<both<<endl;
  history.push_back(both);
}
  
