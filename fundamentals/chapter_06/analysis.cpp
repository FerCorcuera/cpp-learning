#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>

#include "analysis.h"
#include "input.h"

namespace stock_prices
{
  std::vector<double> remove_invalid(std::vector<double> prices)
  {
    for(auto iterator = prices.begin();
        iterator != prices.end();
       )
    {
      if(negative(*iterator))// this means to get the value at that position (iterator)
        iterator = prices.erase(iterator);
      else
        ++iterator;
    }

    return prices;
  }


  double average(const std::vector<double> & prices)
  {
    if(prices.empty())
      throw std::invalid_argument("Prices cannot be ampty");

    return std::accumulate(prices.begin(), //begin of the iteration
        prices.end(), // end
        double{})/prices.size(); // initial value (now at zero)

  }

  void test_analysis()
  {
    auto got = remove_invalid({-1.3,3.5});
    assert(got.size() == 1);
    assert(got[0] == 3.5);

    try
    {
      average({});
      assert(false);


    }

    catch(const std::exception &)
    {

    }

    assert(average({1.0}) == 1.0);


  }
}



