#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = copy;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (&copy == this)
		return *this;
	this->_target = copy._target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->isSigned())
	{
		return throw std::runtime_error("Form is not signed");
	}
	if (executor.getGrade() > this->getGradeExecute())
	{
		return throw AForm::GradeTooLowException();
	}
	if (rand() % 2)
	{
		std::cout << this->_target << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << "robotomy failed." << std::endl;
	}
}
