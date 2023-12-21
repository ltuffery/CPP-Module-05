#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &intern)
{
	if (this == &intern)
	{

	}
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	const std::string forms[3] = {"presidential", "robotomy", "shrubbery"};
	AForm *form = NULL;
	size_t i = 0;

	for (; i < 3; i++)
	{
		if (name == forms[i])
			break;
	}

	switch (i) {
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
	}

	if (form != NULL)
	{
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	else
	{
		std::cout << "Form not exist" << std::endl;
	}

	return form;
}
