#include <iostream>
#include <algorithm>  // library to include algorithms!
#include <vector>
#include "input.h"
// Includes our header

std::vector<double> get_prices(std::istream & input_stream)
{
  std::cout << "Plese enter some numbers. \n> ";
  std::vector<double> numbers{};
  auto number = stock_prices::get_number(input_stream);
  while(number.has_value())
  {
    numbers.push_back(number.value());
    std::cout << "> ";
    number = stock_prices::get_number(input_stream);

  }

  for (const auto number:numbers)
  {
    std::cout << number << '\n';
  }

  return numbers;
}


int main()
{
  auto prices = get_prices(std::cin); 
  //important, we need to pass by reference the stream, streams can't be cpied
  // and is convenient not to copy them, just link directly the value int o the function
  if(!prices.empty())
  {
    auto result = std::ranges::minmax(prices);
    std::cout << "Min " << result.min << '\n';
    std::cout << "Max " << result.max << '\n';
  }
  // we are using one of the algorithms in the algorithms library, minmax()
  // it can be applied to vectors and return both, the min and max value
  // somethign interesitng is that everything or most of it is written in C++ already,
  // not like pythn were numpy or other librares ususualy use another laguage udner the hoods
  // another interesting thing is that 'result' has its own type, it is not a double nor a container, it ia special constructor for this function
}
