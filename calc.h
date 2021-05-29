#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

using namespace std;

class calc
{
  public:
     void Getinput();                  //get inpout from user 

  private:
     vector <string> history;
     int findCount(string , string );  // use for -= 
     void hisprint();                  // print history
     void Plus(string,string);         // +
     void Minus(string,string);        // -
     void Mult(string,string);         // *
     void Division(string,string);     // /
     void Smaller(string,string);      // <
     void And(string,string);          // &&
     void Or(string,string);           // ||
     void Not(string,string);          // !=
     void Plusassign(string,string);   // +=
     void Minusassign(string,string);  // -=

    
};