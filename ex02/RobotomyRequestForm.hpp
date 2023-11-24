#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{

	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string & target);
		RobotomyRequestForm(const RobotomyRequestForm & copy);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(const RobotomyRequestForm & copy);

		void execute(Bureaucrat const & executor) const;

};

#endif
