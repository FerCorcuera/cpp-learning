#pragma once

#include <expected>
#include <istream>
#include <istream>
#include <string>
#include <vector>

namespace stock_prices
{
  std::expected<double, std::string> get_number(std::istream & input_stream);
  std::vector<double> get_prices(std::istream & input_stream, 
      std::function<void()> promt);


  void test_input();



}


