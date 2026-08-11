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
      '\n'
      );
  return std::unexpected{"That is not a number"};
}


int main()
{
  //vector_insert();
  std::cout<<"Please enter some numbers. \n";
  std::vector<double> numbers{};
  auto number = get_number(std::cin);
  while(number.has_value())
  {
    numbers.push_back(number.value());
    std::cout << "Got" << number.value() << "thanks!\n";
    number = get_number(std::cin);

  }
  std::cout << number.error() << '\n';

  std::cout << "You entered\n";
  for (const auto & number:number)
  {
    std::cout << number << '\n';
  }
}
