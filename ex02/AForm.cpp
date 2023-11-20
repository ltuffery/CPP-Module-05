#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _requiredGradeSigned(1), _requiredGradeExecute(1)
{
	this->_signed = false;
}

AForm::AForm(const AForm &form) : _requiredGradeSigned(form._requiredGradeSigned), _requiredGradeExecute(form._requiredGradeExecute)
{
	*this = form;
}

AForm::AForm(int gradeSigned, int gradeExecute) : _requiredGradeSigned(gradeSigned), _requiredGradeExecute(gradeExecute)
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

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requiredGradeSigned)
	{
		return throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}
