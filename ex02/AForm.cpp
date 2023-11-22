#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _requiredGradeSigned(1), _requiredGradeExecute(1)
{
	this->_signed = false;
}

AForm::AForm(const AForm &form) : _name(form._name), _requiredGradeSigned(form._requiredGradeSigned), _requiredGradeExecute(form._requiredGradeExecute)
{
	*this = form;
}

AForm::AForm(std::string name, int gradeSigned, int gradeExecute) : _name(name), _requiredGradeSigned(gradeSigned), _requiredGradeExecute(gradeExecute)
{
	this->_signed = false;
}

AForm & AForm::operator=(const AForm &form)
{
	if (this == &form)
		return *this;
	this->_signed = form._signed;
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeExecute() const
{
	return this->_requiredGradeExecute;
}

bool AForm::isSigned() const
{
	return this->_signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requiredGradeSigned)
	{
		return throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}
