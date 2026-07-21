#include <cassert>
#include <sstream>

// A function for input with tests
// Writing tests can be a good way to think about disigning code (TDD appraoch)

void test_code()
{
  // assert(0==1);

  double value{};
  std::stringstream some_input{"1"};
  const bool ok = get_number(some_input, value);
  assert(ok);
  assert(value == 1)
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

