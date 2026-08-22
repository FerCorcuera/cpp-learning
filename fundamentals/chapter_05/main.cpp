#include <iostream>
#include <algorithm>  // library to include algorithms!
#include <vector>

#include "input.h"
// Includes our header
#include "analysis.h"


std::vector<double> get_prices(std::istream & input_stream)
{
  std::cout << "Plese enter some numbers. \n> ";
  std::vector<double> numbers{};
  auto number = stock_prices::get_number(input_stream);
  while(number.has_value())
  {
    numbers.push_back(number.value());
    std::cout << ">  ";
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
  stock_prices::test_analysis();
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
  // the second parameter is the condition, something like defining a lambda function

  auto erased = std::erase_if(prices, stock_prices::negative);
  std::cout << erased << " prices below zero eliminated \n";

  // with erase if we eliminate elemetns from a container!
  // similarly it needs a predicate and a conatiner
  // improtant to mention that erase_if erased the input variable and returns the number of erased values
  
  // we also can do it using the old way:
  
  auto invalid_old = std::count_if(
      prices.begin(), prices.end(), stock_prices::negative
      );

  std::cout << invalid_old << " prices below zero using older way \n";

}
