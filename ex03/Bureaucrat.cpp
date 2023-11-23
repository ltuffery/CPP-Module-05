#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

Bureaucrat::Bureaucrat()
{
	this->_name = "default";
	this->_grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
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

void Bureaucrat::signForm(AForm &form)
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

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form.getName();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
