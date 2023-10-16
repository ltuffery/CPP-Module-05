#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _requiredGradeSigned(1), _requiredGradeExecute(1)
{
	this->_signed = false;
}

std::string Form::getName() const
{
	return this->_name;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requiredGradeSigned)
	{
		return throw Form::GradeTooLowException();
	}
	this->_signed = true;
}
