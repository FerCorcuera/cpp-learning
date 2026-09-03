#include <algorithm>
#include <iostream>
#include <vector>

#include "input.h"

std::vector<double> get_prices(std::istream & input_stream)
{
  std::cout << "Please enter some numbers. \n";
  std::vector<double> numbers{};
  auto number = stock_prices::get_number(input_stream);
  while (number.has_value())
  {
    numbers.push_back(number.value());
    std::cout << "> ";
    number = stock_prices::get_number(input_stream);

  }
}



// Lambda functions: as in python, lambda functions are unnamed fucntions that should 
// be used mainly for short implementations, and they should show clearly what are they doing
// the structure is like auto [](double value){return value < 0.0}
// so they take parameteres as usual functions do, and return an implementation
// we can define labmdas earlier , store them in a variable and use it later.
// Interesting, each lambda function has its own type, even if both are defined in the same way

int main()
{
  std::vector prices{1.01, 2.02, 3.03, -4.03};
  auto lambda = [](double value){ return value < 0.0;};
  auto erased = std::erase_if(prices, lambda);
  std::cout << erased << "  PRICES BELOW ZERO \n";
}
