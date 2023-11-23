#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>

class Bureaucrat;

class Form
{

	private:
		const std::string _name;
		bool _signed;
		const int _requiredGradeSigned;
		const int _requiredGradeExecute;
	
	public:
		Form();
		Form(std::string name, int gradeSigned, int gradeExecute);
		Form(const Form &copy);
		~Form();

		Form & operator=(const Form &form);

		std::string getName() const;
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};


};

#endif
