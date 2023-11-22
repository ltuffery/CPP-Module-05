#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (&copy == this)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	// TODO : implement...
}
