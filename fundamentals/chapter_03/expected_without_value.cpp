#include <expected>
#include <iostream>
#include <string>

//std::expected is a class template!
//is like saying " I will contain either a sucessful value or information describing a failiure"
//but c++ needs to know what is the type of sucess and what type the failure is!
// so here "double" is the sucess object and std::string the failure!

std::expected<double, std::string>get_number(
    std::istream& input_stream
    )
{
  double number {};
  input_stream >> number;
  if(input_stream)
  {
    return number;
  }
  return std::unexpected{"That's not a number"};
}


int main()
{
  std::cout << "Please enter a number \n";
  auto number = get_number(std::cin); // auto is a place holder type! the compiler fill the appropiate type for you!
  if (number)
  {
    std::cout << "Got " << number.value() << " Thanks! \n";
  }
  // instead of trying first to check if the number has value
  // we can use the same simple boolean appraoch! 

  else
  {
    std::cout << "AI please don't take my job!\n";
  }

}
