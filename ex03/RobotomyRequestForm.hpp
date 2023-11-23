#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm & copy);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(const RobotomyRequestForm & copy);

		void execute(Bureaucrat const & executor) const;

};

#endif
