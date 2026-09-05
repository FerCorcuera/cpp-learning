#include <iostream>
#include <ranges>
#include <vector>

#include "input.h"
#include "analysis.h"
// be used mainly for short implementations, and they should show clearly what are they doing
// the structure is like auto [](double value){return value < 0.0}
// so they take parameteres as usual functions do, and return an implementation
// we can define labmdas earlier , store them in a variable and use it later.
// Interesting, each lambda function has its own type, even if both are defined in the same way

// the brackets indicate what variables from outside we want to use
// and the parenthesis and braces are like a normal function

int main()
{

  stock_prices::test_input();

  std::cout << "Please enter some numbers. \n";
  auto promt = [](){ std::cout << '>';};
  auto prices = stock_prices::get_prices(std::cin, promt);
  std::cout << "Got " << prices.size() << " price(s) \n";

  std::cout <<"The following are valid. \n";
  auto valid_prices = std::views::filter(prices,
      [](double p) {return p >= 0.0;} );
  // we are using views instead of copying directly the orignal vector
  // also , valid_prices is not a vector is  VIEW!!
  // it stores a reference or conneection with the original vector!

  for(double price : valid_prices)
  {
    std::cout << price << '\n';
  }

  const auto valid_prices_as_vector = std::ranges::to<std::vector>(
      valid_prices
      );

  const double mean = stock_prices::average(
      valid_prices_as_vector 
      );

  std::cout << "with average > " << mean << '\n';


}
