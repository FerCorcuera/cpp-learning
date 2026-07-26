#include <cassert>
#include <sstream>
#include <istream>

// A function for input with tests
// Writing tests can be a good way to think about disigning code (TDD appraoch)
// A stream is an object that provides sequantial acces to data!
// doest not matter where that data come from or goes to
// So std:stringstream is a class that need a predefined input
// And it behaves interestingly, the object stores some stirng and
// can store the content in deiffernt variables with different types, interpreting their type

bool get_number(std::istream & input_stream , double & number)
{
  number = 1;
  return true;
}
  
// first we need to recall the & operator, that links a variable with other
// that is usefull since we only need to call the function and the imput variable will change!
// for example: int& x means osmething like "x is a reference of an existing variable of type int"
// so it needs two sides, the left side means the type and the right side the name that we want to give to this linked
void test_code()
{
  // assert(0==1);

  double value{};
  std::stringstream some_input{"1"};
  const bool ok = get_number(some_input, value);
  assert(ok);
  assert(value == 1);
}

// We are writing the test_code before main, if we call it before
// the compiler sees a declaration or definition, there will be an error
// The compiler needs to know aobut the function before you can use it!
// we can put the declaration first and then define the function, that is for later

// Breaking your code into function
// void a_function(int value) value is a new variable!
// void another_function(int & value) value is another name for the input (a reference)

int main()
{
  test_code();
}

