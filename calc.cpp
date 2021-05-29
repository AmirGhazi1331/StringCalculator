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
  if(temp[1]=="*")
  {
      Mult(temp[0],temp[2]);
  }
  if(temp[1]=="/")
  {
      Division(temp[0],temp[2]);
  }
  if(temp[1]=="<")
  {
      Smaller(temp[0],temp[2]);
  }
  if(temp[1]=="&&")
  {
      And(temp[0],temp[2]);
  }
  if(temp[1]=="||")
  {
      Or(temp[0],temp[2]);
  }
  if(temp[1]=="!=")
  {
      Not(temp[0],temp[2]);
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
  int finallen ; //keep First - Second or Second - First
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

void calc::Mult(string First, string Second)
{
  string Final; //keep output string 
  if(First.length()>=Second.length()) // check len of strings
  {
    for(int i =0;i<First.length();i++)
    {
      Final+=Second;
    }
    cout<<Final<<endl; 
    history.push_back(Final);
  }
  else 
  {
    for(int i =0;i<Second.length();i++)
    {
      Final+=First;
    }
    cout<<Final<<endl;
    history.push_back(Final);
  }
  
}
void calc::Division(string First, string Second)
{
  int firstint[First.length()]; //cast chars to int
  int secondint[Second.length()];
  for(int i=0;i<First.length();i++)
  {
    firstint[i]=(int)First[i];
  }
  for(int i=0;i<Second.length();i++)
  {
    secondint[i]=(int)Second[i];
  }
  //check if there is any char of Second in First
  for(int i=0;i<First.length();i++) 
  {
    for(int j=0;j<Second.length();j++)
    {
      if(firstint[i]==secondint[j]-32)
      {
        firstint[i]+=32; //if there is cast it to lower (A to a)
      }
    }
  }
  string output;
  for(int i=0;i<First.length();i++)
  {
    output+=(char)firstint[i];
  }
  cout<<output<<endl;
  history.push_back(output);
}

void calc::Smaller(string First, string Second)
{
  int firstint[First.length()]; //cast First chars to int
  for(int i=0;i<First.length();i++) 
  {
    firstint[i]=(int)First[i];
  }
  int target = (int)Second[0]; 
  string output;
  for(int i=0;i<First.length();i++)
  {
    if(firstint[i]<target)
    {
      output+=(char)firstint[i]; // add chars below the target
    }
  }
  cout<<output<<endl;
  history.push_back(output);
}
void calc::And(string First, string Second)
{
  bool left=false;
  bool right = false;
  string target="aeiou";
  for(int i=0;i<First.length();i++) 
  {
    for(int j=0;j<target.length();j++)
    {
      if(First[i]==target[j])
      {
        left=true;
      }
    }
  }
  for(int i=0;i<Second.length();i++) 
  {
    for(int j=0;j<target.length();j++)
    {
      if(Second[i]==target[j])
      {
        right=true;
      }
    }
  }
  if(left==true&&right==true)
  {
    cout<<"True"<<endl;
    history.push_back("True");

  }
  else
  {
    cout<<"False"<<endl;
    history.push_back("False");
  }
}

void calc::Or(string First, string Second)
{
  bool left=false;
  bool right = false;
  string target="aeiou";
  for(int i=0;i<First.length();i++) 
  {
    for(int j=0;j<target.length();j++)
    {
      if(First[i]==target[j])
      {
        left=true;
      }
    }
  }
  for(int i=0;i<Second.length();i++) 
  {
    for(int j=0;j<target.length();j++)
    {
      if(Second[i]==target[j])
      {
        right=true;
      }
    }
  }
  if(left==true||right==true)
  {
    cout<<"True"<<endl;
    history.push_back("True");

  }
  else
  {
    cout<<"False"<<endl;
    history.push_back("False");
  }
}

void calc::Not(string First, string Second)
{
  string left;
  string right;
  char target=Second[0];
  int i=0;
  while(First[i]!=target)
  {
    
    left+=First[i];
    i++;
  }
  right= First.substr(left.length()+1,First.length());
  string output=right +Second[0]+ left;
  cout<<output<<endl;
  history.push_back(output);
}
