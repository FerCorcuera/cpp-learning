#include <iostream>

// eof() is a member function in the input stream, so it is part from cin
// eof stands for "End of file"
// Member functions need to be called with dot operator
// So now we are calling an instance function, not a class function (where we used ::)

if(!std::cin.eof()) // so this could be read as
                    // check if we have reached the end of the stream
{
  std::cout << "Unused input\n"
}
