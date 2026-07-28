#include <exception>
#include <iostream>

// An exceptiion has threep arts, try , throw and catch! 

double get_number(std::istream & input_stream)
{
  double number{};
  input_stream >> number;
  if(input_stream)
  {
    return number;
  }

  throw std::exception{}; // here throw seems to replace an else statement
                          // but no! it is only placed here because if the if statement fails
                          // aumtomatically an exception will be raised
}


// IMPORTANT: if something geos wrong the program looks for a catch block
// remember the concept of scope, it is the block of code where the program is living (inside brackets)
// so the program will start looking for a catch in the current scope and will keep looking for it in the next closing braces

int main()
{
  
  try
  {
    std::cout << "Please enter a number > \n";
    double number = get_number(std::cin);
    std::cout << " Got " << number << " thanks!\n";

  }
  
  catch(const std::exception & ex) // this indicates whre the exception needs to go after happening
  {
    std::cout << "Something went wrong \n";
  }


  }
