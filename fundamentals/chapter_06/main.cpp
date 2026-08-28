#include <algorith>
#include <iostream>
#include <vector>

int maion()
{
  std::vector prices{1.01, 2.02, 3.03, -4.03};
  auto lambda = [](double value){ return value < 0.0};
  auto erased = std::erase_if(prices, lambda);
  std::cout << erased << "PRICES BELOW ZERO \n";
}
