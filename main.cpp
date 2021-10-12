#include <iostream>
#include "fib.h"

int main()
{
	std::cout << "Hello world " << std::endl;
	std::cout << fib(5) << std::endl;
    std::cout << fib_opt(5) << std::endl;
	return 0;
}
