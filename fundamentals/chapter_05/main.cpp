#include <iostream>
#include <algorithm>
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
}
