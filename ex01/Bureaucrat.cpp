#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

Bureaucrat::Bureaucrat(): _name("default")
{
	this->_grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout 
			<< this->getName() 
			<< " couldn’t sign " 
			<< form.getName() 
			<< " because " 
			<< e.what() 
			<< std::endl;
	}
}

void Bureaucrat::upGrade()
{
	int new_grade = _grade - 1;

	if (new_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade = new_grade;
}

void Bureaucrat::downGrade()
{
	int new_grade = _grade + 1;

	if (new_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = new_grade;
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
