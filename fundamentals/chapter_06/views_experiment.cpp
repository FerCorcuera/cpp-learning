#include <iostream>
#include <ranges>
#include <vector>

int main()
{
  const std::vector prices{3.76,1.5, -1.0, 3.0, 4.0, -2.0, 99.4};
  const double required_price{4.75};
  auto non_negative = [](double price){return price >= 0.0;};
  auto too_cheap = [required_price](double x)
  {
    return x <= required_price;
  }
  auto valid_prices = std::views::take_while(valid_prices, too_cheap);
  auto no_good = std::views::take_while(valid_prices, too_cheap);
  std::cout << "Too cheap \n";
  for(double p : no_good)
  {
    std::cout << p << "Valid prices: \n";
    for(double p :valid_prices)
    {
      std::cout << p << '\n';
    }
  }
}



