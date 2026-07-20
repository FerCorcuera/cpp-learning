#include <iostream>
#include <limits>
// eof() is a member function in the input stream, so it is part from cin
// eof stands for "End of file"
// Member functions need to be called with dot operator
// So now we are calling an instance function, not a class instance (where we used ::)


int main()
{
  const double largest = std::numeric_limits<double>::max();
  std::cout << "Please enter a number up to " <<largest << ".\n>";
  double number {};
  std::cin >> number;
  std::cout << number << '\n';
  if(!std::cin.eof() && std::cin.peek()!='\n')
    // .peek() observes the next character that was left in the buffer
    // both statements could be read as:
    // 1. we have not reached the end of the file
    // 2. The next unread character is not a new line
  {
    std::cout << "Unused input\n";
  }
}

