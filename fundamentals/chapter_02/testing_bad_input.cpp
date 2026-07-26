#include <cassert>
#include <istream>
#include <iostream>
#include <sstream>

[[nodiscard]] bool get_number (
    std::istream & input_stream,
    double & number)
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
    input_stream.clear(); //clears the failed flag
    input_stream.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
        );
    // we ignore the leftover input til the max characters or til \n
    return false;
  }
}
//basically  we are trying to put into "number" the content of input_stream
// if it detecs a number that will be placed inside number (using the bool operator of the intance)
// it will return true, and in the contrary, false
// we are just detcting erros ona stream!

void test_code()
{
  {
    double value{};
    std::stringstream input{"1"};
    const bool ok = get_number(input, value);
    assert(ok);
    assert(value ==1);
  }


  // it is usefull to separate code into blocks using {}
  // but if you have notince that you need separate blocks, 
  // might indicate that we should split the function into smaller named functions

  {
    double value{};
    std::stringstream input{"q"};
    const bool ok = get_number(input, value);
    assert(!ok);
  }
}

// void some_experiments()
//   // we want to try what happns if we change number to an int
// {
//   int number{};
//   bool OK = get_number(std::cin, number);
//   std::cout << OK << '\n';
// }

int main()
{

  test_code();
  // assert(value==1); // you can't use local function variables in the general main

  // std::cout << std::numeric_limits<std::streamsize>::max();

  double number{};
  std::cout << "Please enter a number .\n> ";
  const bool ok = get_number(std::cin, number);


  if(ok)
  {
    std::cout << "Got: " << number << ", thanks!\n";
  }
  else
  {
    std::cout << "Something went wrong\n";
    std::cout << "Please enter a nubmer \n> ";
    const bool ok_now = get_number(std::cin, number);
    if(ok_now)
    {
      std::cout << "Got: " << number << ", thanks!\n";

    }
    else
    {
      std::cout << "Something get wrong again :( \n";
    }
  }
}

// Variables only live inside their functions calls, then, they never exists, 
// this could help you to have more control and with faster and small programs
