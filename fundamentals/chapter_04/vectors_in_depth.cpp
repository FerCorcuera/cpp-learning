#include <vector>
#include <iostream>

// Initializing containers with a initial list
// We can create containers (vectors and arrays) stating the type:


// std::array<int,3> numbers;
// std::vector<int> more_numbers;
//
// but also we can ues class template argument deducation (CTAD), 
// and the complier will deduce those paramters for us:


// std::array numbers_x{1,4,-3};
// std::vector other_numbers{2,3,4};

// the types of the elements in the curly braces are going to define
// the parameters! but if we tray to mix the number types inside the container:

// std::vector numbers_v{0,1,2.5};

// there will be an error, and why? Because these types represnt different subtle informatin

// double x = 0;
// int y = 0.0; //we are possible losing information!

// how can we define correctly these conatinesrs?

// std::vector<double> numbers_va{0,1,2.5}; //forcing the state that we want
// std::vector numbers_xd{0.0,1.0,2.5}; // or making all numbers the same type

void remove_from_vector()
{
  std::vector numbers{1,3,7,9,0};
  numbers.erase(numbers.begin());
  numbers.erase(numbers.begin() + 1, numbers.begin() +2);
  for (const auto number : numbers)
  {
    std::cout << number << '\n';
  }

  std::cout << "Capacity " << numbers.capacity() << '\n';
  numbers.shrink_to_fit();
  std::cout << "Capacity " << numbers.capacity() << '\n';

}

int main()
{
  std::vector numbers{0,1};
  std::cout << "Space for " << numbers.capacity() << '\n';
  numbers.push_back(2);
  std::cout << "Space for " << numbers.capacity() << '\n';

  remove_from_vector();

}

// we need to disntinguish between size (the number of elements)
// and capacity = how many elemetns can fit before allocating more memory
// and this is really interesing! the compiler is adding 2 more spaces instead of 1 
// I wantto think aobut this like a shelf, we only have two books for example but we 
// buy a shelter that is for 10, even if we'll buy a couple more tomorrow
