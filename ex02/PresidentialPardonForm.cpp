#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) : AForm(25, 5)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (&copy == this)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	// TODO : implement...
}
