#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("me", 0);
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what();
	}
}
