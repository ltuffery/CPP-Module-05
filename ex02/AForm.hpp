#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>

class Bureaucrat;

class AForm
{

	private:
		const std::string _name;
		bool _signed;
		const int _requiredGradeSigned;
		const int _requiredGradeExecute;
	
	public:
		AForm();
		AForm(int gradeSigned, int gradeExecute);
		AForm(const AForm &copy);
		~AForm();

		AForm & operator=(const AForm &form);

		std::string getName() const;
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : std::exception
		{
			public:
				const char * what() const throw();
		};


};

#endif