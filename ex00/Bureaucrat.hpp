#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

	private:
		int _grade;
		const std::string	_name;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		int getGrade() const;
		std::string getName() const;
		void upGrade();
		void downGrade();

		class GradeTooHighException : public std::exception {

			public:
				const char * what() const throw();

		};
		class GradeTooLowException : public std::exception {

			public:
				const char * what() const throw();

		};

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat &bureaucrat);

#endif
