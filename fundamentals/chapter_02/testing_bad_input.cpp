#include <cassert>
#include <istream>
#include <iostream>
#include <sstream>

[[nodiscard]] bool get_number (std::istream & input_stream, double & number)
  // you cann add teh [[nodiscard]] feature if the function return is not
  // assiged to anything, the compiler will show a useful warning!
{
  input_stream >> number;
  if(input_stream)
  {
    return true;
  }
  else
  {
    return false;
  }
}
//basically  we are trying to put into "number" the content of input_stream
// if it detecs a number that will be placed inside number (using the bool operator of the intance)
// it will return true, and in the contrary, false
// we are just detcting erros ona stream!

void test_code()
{
  double value{};
  std::stringstream some_input{"1"};
  const bool ok = get_number(some_input, value);
  assert(ok);
  assert(value ==1);


  double unused{};
  std::stringstream bad_input{"q"};
  const bool not_ok = get_number(bad_input, unused);
  assert(!not_ok);
  assert(value == 1);
}


int main()
{
  test_code();

  double number{};
  std::cout << "Please enter a number .\n> ";

  if(get_number(std::cin,number))
  {
    std::cout << "Got: " << number << ", thanks!\n";
  }
  else
  {
    std::cout << "Something went wrong\n";
  }
}

