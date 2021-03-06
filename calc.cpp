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
  if(temp[0].empty()==true||temp[1].empty()==true||temp[2].empty()==true)
  {
    if(temp[0]=="history")
    {
       hisprint();
    }
    else
    {
       throw "your order is not valid";
    }
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
  if(temp[1]=="+=")
  {
      Plusassign(temp[0],temp[2]);
  }
  if(temp[1]=="-=")
  {
      Minusassign(temp[0],temp[2]);
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
  for(auto i:firstint)
  {
    if(i>90)
    {
      throw "left operand is not valid";
    }
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
  if(Second.length()>1)
  {
    throw "right operand should contain 1 char";
  }
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
  if(Second.length()>1)
  {
    throw "right operand should contain 1 char";
  }
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
void calc::Plusassign(string First, string Second)
{
  string output;
  for(int i=0;i<First.length();i++)
  {
    string temp;
    temp += First[i];
    temp += Second[0];
    output+=temp;
  }
  cout<<output<<endl;
  history.push_back(output);
}
void calc::Minusassign(string First, string Second)
{
  if(Second.length()>First.length())
  {
    throw "right operand should be equal or less than left operand";
  }
  int count = findCount(First, Second); //count Second in First
  int place;
  for(int i=0;i<count;i++) // Repeat for every second in First
  {
    place=First.find(Second); // find index 
    First.erase(place, Second.length());//remove 
  }
  cout<<First<<endl;
  history.push_back(First);
}
void calc::hisprint()
{
  for(auto h:history)
  {
    cout<<h<<endl;
  }
}
int calc::findCount(string str1, string str2)
{
  int len = str1.size();
  int len2 = str2.size();
  int ans = INT_MAX;
 
  // Initialize hash for both strings
  int hash1[26] = { 0 }, hash2[26] = { 0 };
 
  // hash the frequency of letters of str1
  for (int i = 0; i < len; i++)
      hash1[str1[i] - 'a']++;
 
  // hash the frequency of letters of str2
  for (int i = 0; i < len2; i++)
      hash2[str2[i] - 'a']++;
 
  // Find the count of str2 constructed from str1
  for (int i = 0; i < 26; i++)
      if (hash2[i])
          ans = min(ans, hash1[i] / hash2[i]);
 
  // Return answer
  return ans;
}