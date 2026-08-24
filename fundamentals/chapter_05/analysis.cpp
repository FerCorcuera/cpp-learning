#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "analysis.h"
#include "input.h"

namespace stock_prices
{
  std::vector<double> remove_invalid(std::vector<double> prices)
  {
    auto new_end = std::remove_if(prices.begin(), prices.end(), negative);
    prices.erase(new_end, prices.end());
    return prices;
    
  }


  void test_analysis()
  {
    auto got = remove_invalid({-1.2,3.5});
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

    assert(average({1.0}) == 1.0)
  }

  double average(const std::vector<double> & prices)
  {
    // double sum{0,0};
    // for(const double & price: prices)
    // {
    //   sum += price;
    // }
    //
    // return sum/prices.size();
    return 0.0;
  }
}


