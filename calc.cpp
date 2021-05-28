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
  if(temp[1]=="+")//check operator and call function
  {
      Plus(temp[0],temp[2]);
  }
  if(temp[1]=="-")
  {
      Minus(temp[0],temp[2]);
  }
}

void calc::Plus(string First, string Second)
{
  string both = First + Second;
  sort(both.begin(), both.end());
  cout<<both<<endl;
  history.push_back(both);
}

void calc::Minus(string First, string Second)
{
  int finallen ;
  if(First.length()>=Second.length())
  {
     finallen = First.length()-Second.length();
     cout<<finallen<<" "<<First.substr(0,finallen)<<endl;
     history.push_back(First.substr(0,finallen));
  }
  else 
  {
     finallen = Second.length()-First.length();
     cout<<finallen<<" "<<Second.substr(0,finallen)<<endl;
     history.push_back(Second.substr(0,finallen));
  }
  
}
