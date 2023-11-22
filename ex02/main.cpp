#include "Bureaucrat.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(void)
{
	std::srand(time(0));
	{
		try
		{
			Bureaucrat a("me", 0);
			std::cout << a << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat a("test", 151);
			std::cout << a << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat a("main", 10);
			std::cout << a << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
	}
}
