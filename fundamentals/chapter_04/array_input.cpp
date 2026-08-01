#include <array>
#include <iostream>
#include <expected>

//experimenting with arrays in cpp
// array is a clas template, the diffence between it and a class
// is that a class template is like blueprint to generate other classes
// so one template can generate several classe, 

std::expected<double,std::string> get_number(
    std::istream & input_stream
    )
{
  double number{};
  input_stream >> number;
  if(input_stream)
  {
    return number;
  }
  input_stream.clear(); // we clear errors

  input_stream.ignore(
      std::numeric_limits<std::streamsize>::max(),
      '\n'
      // hhere we thorw all the characters until we find a new line
      // or until we reach to the maximum accepted value
      );

  return std::unexpected{"That's not a number "};
}

void array_experiment()
{
  std::array<double,5> numbers{};
  // std::array numbers {1.1 , 2.2. , 3.3 , 4.4, 5.5};
  // we can define the array also lke this withotu specifying the type and the legnth
  // given that the complier deducts the parameters
  std::cout << numbers[0] << '\n';
  numbers[0] = 2.5;
  std::cout << numbers[0] << '\n';

}

int main()
{
  // array_experiment();

  std::cout << "Please enter some numbers: \n";
  std::array<double,5u> numbers{}; // u stands for unsigned number (no negative)
  size_t count{0u}; //size_t is another type 
  while (count < numbers.size())
  {
    std::cout << '>';
    auto number = get_number(std::cin);
    if(number.has_value())
    {
      numbers[count] = number.value();

      std::cout << "Got" << number.value() << " thanks! \n";

      ++count;

    }

    else
    {
      std::cout << number.error() << "\n";
    }
    
        // when we use the ++ operator increments the varaible
    // if is like ++X , increments first and then return the value
    // if is like X++, returns the value first and then increments
  }
}
