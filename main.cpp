#include <iostream>
#include "calc.h"
using namespace std;

int main()
{
  calc calculator;
  loop:
  try
  {
    calculator.Getinput();
  }
  catch (const char* msg) 
  {
    cerr << msg << endl;
  }
  goto loop;
  return 0;
}