#include <iostream>

#include "input.h"

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
}
