#include <iostream>
#include <random>
#include "input.h"

void random_experiment()
{

  std::random_device rd{}; // makes a random device to generate a seed
  std::default_random_engine generator(rd()); // makes an engine, using the random seed 
  std::uniform_int_distribution<int> distribution{1,6}; //makes a distribution
  const int roll = distribution(generator); // we use the distribution to create our numbers

  // important, with this code we are not creating the random number 
  // we are creating the object that defiens how random numbers will be generated

  std::cout << "Dice roll " << roll << '\n';

}


int main()
{
  random_experiment();
  stock_prices::test_input();
  const auto prices = stock_prices::get_prices(100.0, 10);
  std::cout << "Got prices: \n";
  for(double price: prices)
  {
    std::cout << price << '\n';
  }

}
