#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main(void)
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

	try
	{
		Bureaucrat a("main", 10);
		Form f("name", 5, 5);

		f.beSigned(a);
		std::cout << "Signed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("main", 10);
		Form f("name", 10, 10);

		f.beSigned(a);
		std::cout << "Signed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("main", 10);
		Form f("name", 11, 10);

		f.beSigned(a);
		std::cout << "Signed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
