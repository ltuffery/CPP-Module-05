#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm & copy);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm & copy);

		void execute(Bureaucrat const & executor) const;

};

#endif
