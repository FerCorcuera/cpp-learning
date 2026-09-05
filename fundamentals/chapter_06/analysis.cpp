#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>

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

  double profit_on_first_uptick(const std::vector<double> & prices)
  {
    if(prices.empty())
      throw std::invalid_argument("Prices cannot be empty!!");

    const double first = prices.front();
    auto where = std::ranges::find_if(prices,
        [first](double price){return price > first;}
        );
      // here we iterate through the values in prices to check for the first price
      // that is more than the first price


    if(where != prices.end())
    {
      return *where - first; // checks that we are not at the end, that would mean that no price was higher than the fisrt one
      
    }
    else
    {
      return 0.0;
    }
      
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



