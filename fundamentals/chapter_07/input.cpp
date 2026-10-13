#include <algorithm>
#include <cassert>
#include <limits>
#include <sstream>
#include <random>

#include "input.h"

namespace stock_prices

{
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
    return std::unexpected{"That is not a number"}
  }


  std::vector<double> get_prices(double price, size_t count)
  {
    std::vector<double> prices(count);
    const double step = price/100;

    std::random_device rd{};
    std::default_random_engine gen(rd());
    std::uniform_int_distribution distrib{-1,1};

    auto next_price = [step, &price, &gen, &distrib]()
    {
      price += step * distrib(gen);
      return price;
    };

    std::ranges::generate(prices.begin(), prices.end(), next_price);
    return prices;


  }

  void test_input()
  {
std::stringstream no_input{""};
    auto no_op = [](){};
    assert(get_prices(no_input, no_op).empty());
    
    std::stringstream some_input{"1"};
    assert(get_prices(some_input, no_op).size() == 1);
  }

}
