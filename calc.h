#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

using namespace std;

class calc
{
  public:
     void Getinput();
     void Plus(string,string);
     void Minus(string,string);
     void Mult(string,string);
     void Division(string,string);
     void Smaller(string,string);
     void And(string,string);
     void Or(string,string);

     

  private:
     vector <string> history;
    
};