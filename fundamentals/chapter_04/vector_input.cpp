#include <iostream>
#include <vector>

// vectors are differnt from arrays in cpp
// they are dynamic in size and in elements, they can grow of shrink over time
// so we only need to spcecy the type, and even if not, the complier will  do it for us
// but that flexibilty comes with more responsability, under the hoods, vectors allocate memory and alot of other things in order to housekeep the elemetns and how they change
// although, both vectors and arrays are considered containers, each container has special features

void vector_experiment()
{
  std::vector numbers{1,0};
  numbers.push_back(-123); //add another element to end with push_back
  for (const auto number:numbers)
  {
    std::cout << number << '\n';
  }
}

void vector_insert()
{
  std::vector<int> numbers{1,0};
  // numbers.insert(numbers.begin(),-123); // .begin() is an interator that indicates the beginning of the vector
  auto iterator = numbers.begin();
  numbers.insert(++iterator, -123); // we are using .begin to find the first positiion and add one unit to point the second position
  for (const auto number:numbers)
  {
    std::cout << number << '\n';
  }
}

// we can also use the [] to acces to an element, like in arrays,
// nothing stops us for going forward or backward but,
// we end outside the elemetns that is an undefined behavior and bad things happen

// we can aslo use .at() like number.at(9) to acces the position value
// the only difference is that the program will check if the elment exists,
// reporting the error first
int main()
{
  vector_experiment();
  vector_insert();
}

