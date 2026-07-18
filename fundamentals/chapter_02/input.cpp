#include <iostream>

// This will be a file to experiment how to take inputs return outputs
// First of all we need a variable where to store the inputs

int main ()
{
  // // we can create a variable like this
  // int number = 0; 
  // // or also we can do it like this
  //
  // // we can change the "content" fo the variable at any time,
  // // without declaring the type again!
  // number = 42;
  //
  // // we can create constant variables that does not change its value
  // // if we try it , it will be an erro
  // const int number_1{1};
  // number_1 = 73;
  
  // output uses the operator <<
  // input uses the operator >>

  std::cout<<"Please enter an number.\n> ";
  double number{}; // we can change the declartion of the variable
  std::cin >> number;
  std::cout <<number<<'\n'; 

  int largest_int = std::numeric_limits<int>::max();
  // this could be thinked as:
  // 1. go into the std library (namespace really)
  // 2. find the template (class template) numeric_limits
  // 3. Make the int version 
  // 4. inside that class lets call the max(0 tool)
  double largest_double = std::numeric_limits<double>::max();

  std::cout <<largest_int<<'\n'<<largest_double<<'\n';
  
}



