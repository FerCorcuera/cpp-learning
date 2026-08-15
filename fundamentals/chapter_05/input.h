#pragma once
// when the number of files increases, it is important to avoid double calling a file
// we can do this with pragma once, it checks if the header has already been imported, and if so,
// avoids a second import


#include <expected>
#include <iostream>
#include <string>

// we declare the function, this is an important difference!
// is just like saying to the compiler 'hey , this function exists somewhere'

namespace stock_prices
{
  std::expected<double,std::string> get_number(std::istream & input_stream);
}

