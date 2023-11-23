#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & copy);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm & copy);

		void execute(Bureaucrat const & executor) const;

};

#endif
