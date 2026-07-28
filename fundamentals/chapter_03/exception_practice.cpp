#include <exception>
#include <iostream>
#include <stdexcept>

// here we are learning in a little more depth about handling exceptions
// the stdexcept ilbrary header provides other exception classes

double get_number(std::istream & input_stream)
{
  double number {};
  input_stream >> number;
  if(input_stream)
  {
    if (number >= 0.0)
    {
      return number;
    }

    throw std::invalid_argument("Please provide a nonnegative number");
    // the text inside the instance is the content that is saved in the .what() function
    // we create an instance of invalid_argument exception! which suits for invalid values
  }
  throw std::exception{};
  // we still are including the general exception! so we need to be careful
  // and define waht block of code will receive each exception
}

int main()
{
  try 
  {
    std::cout << "Please enter a number > \n";
    double number = get_number(std::cin);
    std::cout << "Got " << number << " thanks! \n";

  }

  catch(const std::invalid_argument & ex)
  {
    std::cout << ex.what() << '\n';
  }

  catch(const std::exception & ex)
  {
    std::cout << "Something went wrong\n";
  }
}
