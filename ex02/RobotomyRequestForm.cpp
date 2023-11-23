#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

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
	if (!this->isSigned())
	{
		return throw "Form is not signed";
	}
	if (executor.getGrade() > this->getGradeExecute())
	{
		return throw AForm::GradeTooLowException();
	}
	if (rand() % 2)
	{
		std::cout << executor.getName() << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << "robotomy failed." << std::endl;
	}
}
