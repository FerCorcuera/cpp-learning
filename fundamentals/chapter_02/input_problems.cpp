# include <iostream>

// std::cin is like a class instance, that is the reason 
// why it can 'save' content or states of previous calls

int main()
{
  std::cout << "Please enter a number.\n";
  double number {};
  std::cin >> number;
  if(std::cin) //here the if statement is calling the boolean operator directly
  {
    std::cout << number << '\n';
  }
  else
  {
    std::cout << "Something went wrong\n";
  }
}
