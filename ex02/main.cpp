#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
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
		Bureaucrat a("first", 1);
		Bureaucrat z("last", 150);

		try
		{
			ShrubberyCreationForm shrubberyCreationForm;
			RobotomyRequestForm robotomyRequestForm;
			PresidentialPardonForm presidentialPardonForm;

			shrubberyCreationForm.beSigned(a);
			robotomyRequestForm.beSigned(a);
			presidentialPardonForm.beSigned(a);

			shrubberyCreationForm.execute(a);
			robotomyRequestForm.execute(a);
			presidentialPardonForm.execute(a);
			std::cout << "Form execute" << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			ShrubberyCreationForm shrubberyCreationForm;

			shrubberyCreationForm.execute(a);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			RobotomyRequestForm robotomyRequestForm;

			robotomyRequestForm.beSigned(z);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
