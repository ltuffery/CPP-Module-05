#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) : AForm("PresidentialPardonForm", 25, 5)
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
	if (!this->isSigned())
	{
		return throw "Form is not signed";
	}
	if (executor.getGrade() > this->getGradeExecute())
	{
		return throw AForm::GradeTooLowException();
	}

	std::cout << executor << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
