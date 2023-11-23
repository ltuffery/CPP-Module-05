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
		AForm(std::string name, int gradeSigned, int gradeExecute);
		AForm(const AForm &copy);
		virtual ~AForm();

		AForm & operator=(const AForm &form);

		std::string getName() const;
		int getGradeExecute() const;
		bool isSigned() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

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
