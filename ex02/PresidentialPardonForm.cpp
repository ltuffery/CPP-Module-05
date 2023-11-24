#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = copy;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (&copy == this)
		return *this;
	this->_target = copy._target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->isSigned())
	{
		return throw std::runtime_error("Form is not signed");
	}
	if (executor.getGrade() > this->getGradeExecute())
	{
		return throw AForm::GradeTooLowException();
	}

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
