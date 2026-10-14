#pragma once

#include <expected>
#include <istream>
#include <functional>
#include <string>
#include <vector>

namespace stock_prices
{
  std::expected<double, std::string> get_number(std::istream & input_stream);
  std::vector<double> get_prices(double price, size_t count); 

  void test_input();
}
