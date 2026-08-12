#include <expected>
#include <iostream>
#include <limits>
#include <vector>

std::expected<double, std::string> get_number(
    std::istream & input_stream
    )
{
  double number{};
  input_stream >> number;
  if(input_stream)
  {
    return number;
  }
  input_stream.clear();
  input_stream.ignore(
      std::numeric_limits<std::streamsize>::max(),
      '\n' // this means 'throw away everything until you rech a \n, no matter how many characters are there'
      );
  // it is important to ignore or delete the input taht was not a number
  // we are using the numeric_limits template to remove the conetnt in the buffer
  // .clear() only fixes the state of the stream, but not the characters!

  return std::unexpected{"That is not a number"};
}


int main()
{
  //vector_insert();
  std::cout<<"Please enter some numbers. \n";
  std::vector<double> numbers{};
  auto number = get_number(std::cin);
  while(number.has_value()) // we wil loop while we have a correct value 
  {
    numbers.push_back(number.value()); // we use push_back to include that number in the vector
    std::cout << "Got " << number.value() << " thanks!\n";
    number = get_number(std::cin); // we need to call a number again 
    // in order to continue the loop otherwise we'll be entering the same number and over again

  }
  std::cout << number.error() << '\n';

  std::cout << "You entered\n";
  for (const auto & number:numbers) // here we display the numbers in the vector
  {
    std::cout << number << '\n';
  }
}
