#include <iostream>
#include <ranges>
#include <vector>

// int main()
// {
//   const std::vector prices{3.76,1.5, -1.0, 3.0, 4.0, -2.0, 99.4};
//   const double required_price{4.75};
//   auto non_negative = [](double price){return price >= 0.0;};
//   auto too_cheap = [required_price](double x)
//   {
//     return x <= required_price;
//   };
//   auto valid_prices = std::views::filter(prices, non_negative);
//   // we can write this also as:
//   // auto valid_prices = prices | std::views::filter(non_negative);
//   // the | means to pipe prices through the filter
//   auto no_good = std::views::take_while(valid_prices, too_cheap);
//   //inteeresting, a view intance that is supposed to receive another view instance!
//
//   // we could generlized everyhing with:
//   // auto no_good = prices | std::views::filter(non_negative) | std::views:take_while(too_cheap);
//   std::cout << "Too cheap \n";
//
//   for(double p: no_good)
//   {
//     std::cout << p << '\n';
//
//   }
//
//   std::cout << "Valid prices: \n" ;
//   for (double p:valid_prices)
//   {
//     std::cout << p << '\n';
//   }
// }
//
//


int main()
{
  const std::vector prices{3.76, 1.5, -1.0, 3.0, 4.0, -2.0, 99.4};
  const double required_price = 4.75;
  auto non_negative = [](double price){return price >= 0.0;};
  auto too_cheap = [required_price](double price)
  {
    std::cout << "Comparing " << price << '\n';
    return price <= required_price;
  };
  auto no_good = prices | std::views::filter(non_negative)
                        | std::views::take_while(too_cheap);
  std::cout << "Too cheap:\n";

  for (double p:no_good)
  {
    std::cout << p << '\n';
  }
}
