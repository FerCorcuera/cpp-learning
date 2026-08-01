#include <iostream>
#include <expected>
#include <string>


// learning how to input several number in our program
// we wil use the while loop with our get_number function

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

  while(true)
  {
    auto number = get_number(std::cin);

    if (number.has_value()) // we check if the numer has a correct value
    {
      std::cout << "Got " << number.value() << " Thanks! \n";
    }

    else

    {
      std::cout << number.error() << '\n'; // we display the error when there is a string
      break;// breaks if there is an error after printing the error
    }
  }
}

