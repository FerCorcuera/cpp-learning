#include <vector>

// Initializing containers with a initial list
// We can create containers (vectors and arrays) stating the type:


std::array<int,3> numbers;
std::vector<int> more_numbers;

// but also we can ues class template argument deducation (CTAD), 
// and the complier will deduce those paramters for us:


std::array numbers{1,4,-3};
std::vector other numbers{2,3,4};

// the types of the elements in the curly braces are going to define
// the parameters! but if we tray to mix the number types inside the container:

std::vector numbers{0,1,2.5};

// there will be an error, and why? Because these types represnt different subtle informatin

double x = 0;
int y = 0.0; //we are possible losing information!

// how can we define correctly these conatinesrs?

std::vector<double> numbers{0,1,2.5}; //forcing the state that we want
std::vector numbers{0.0,1.0,2.5}; // or making all numbers the same type
