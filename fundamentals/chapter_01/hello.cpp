#include <iostream>

//the header tels the compiler that those names exists somewhere
//once the compiles knows that there exists something called cout inside iostrem
//we specify where exactly is , "using std::"

int main()
{
  std::cout<<"Hello, world!" << '\n';
  // it is interesting how we can include the \n separataor by different ways
  // we can add it like linking with << operations
  // or we can use \n inside the same stream
}


void println(); // void functions do not return anything
void println(/* maybe some parameters*/); 
// these are overload functions, they have the same name but can receive different params

