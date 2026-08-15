#include <limits>
#include <input.h>

namespace stock_prices
{
  std::expected<dobule, std::string> get_number(std::istream& input_stream)
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
}
