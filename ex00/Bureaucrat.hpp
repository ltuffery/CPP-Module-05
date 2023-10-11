#ifndef BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

	private:
		int _grade;
		std::string	_name;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		int getGrade() const;
		std::string getName() const;

		class GradeTooHighException : public std::exception {

			public:
				virtual char * what();

		};
		class GradeTooLowException : public std::exception {

			public:
				virtual char * what();

		};

};

std::ostream & operator<<(std::ostream & os, Bureaucrat &bureaucrat);

#endif
