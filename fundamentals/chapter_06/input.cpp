#include <limits>
#include "input.h"

namespace stock_prices

{
  // function to get one number, check if is a number
  std::expected<double, std::string> get_number(std::istream& input_stream)
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
    return std::unexpected{"That is not a number!"};
  }

  std::vector<double> get_prices(std::istream & input_stream,
      std::function<void ()> promt)
  {
    promt();
    std::vector<double> numbers{};
    auto number = stock_prices::get_number(input_stream);
    while(number.has_value())
    {
      numbers.push_back(number.value());
      prompt();
      number  = stock_prices::get_number(input_stream);

    }
    return numbers;
  }
}
