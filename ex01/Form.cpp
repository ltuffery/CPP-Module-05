#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _requiredGradeSigned(1), _requiredGradeExecute(1)
{
	this->_signed = false;
}

Form::Form(const Form &form) : _name(form._name), _requiredGradeSigned(form._requiredGradeSigned), _requiredGradeExecute(form._requiredGradeExecute)
{
	*this = form;
}

Form::Form(std::string name, int gradeSigned, int gradeExecute) : _name(name), _requiredGradeSigned(gradeSigned), _requiredGradeExecute(gradeExecute)
{
	this->_signed = false;
}

Form & Form::operator=(const Form &form)
{
	if (this == &form)
		return *this;
	this->_signed = form._signed;
	return *this;
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
