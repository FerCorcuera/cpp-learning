#include <algorithm>
#include <iostream>
#include <vector>

#include "analysis.h"
#include "input.h"

std::vector<double> get_prices(std::istream & input_stream)
{
  std::cout << "Please enter a number. \n";
  std::vector<double> numbers{};
  auto number = stock_prices::get_number(input_stream);
  while (number.has_value())
  {
    numbers.push_back(number.value());
    std::cout << '>';
    number = stock_prices::get_number(input_stream);

  }

  return numbers;
}


int main()
{
  auto prices = get_prices(std::cin);
  if (!prices.empty())
  {
    auto result = std::ranges::minmax(prices);
    std::cout  << "min " << result.min << '\n';
    std::cout << "max " << result.max << '\n';

    // we call the minmax function from std library that... does that, find the min and max xd

  }

  auto invalid = std::ranges::count_if(prices, stock_prices::negative);
  std::cout << invalid << " prices below zero  \n";

  // we are calling count_if function in combine with our negative function!
  // the count_if functions counts the elements that satisfy a condition
  // here our condition is given by the inline funciton that we created

  auto erased = std::erase_if(prices, stock_prices::negative);
  std::cout << erased << " prices below zero eliminated";

}
