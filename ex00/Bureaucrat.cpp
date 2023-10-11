#include "Bureaucrat.hpp"

char * Bureaucrat::GradeTooLowException::what()
{
	return "Grade too low\n";
}

char * Bureaucrat::GradeTooHighException::what()
{
	return "Grade too high\n";
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _grade(grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}

	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (&bureaucrat == this)
		return *this;
	this->_name = bureaucrat.getName();
	this->_grade = bureaucrat.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream & operator<<(std::ostream os, const Bureaucrat &bureaucrat)
{
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
