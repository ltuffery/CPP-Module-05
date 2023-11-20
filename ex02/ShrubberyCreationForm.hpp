#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm & copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & copy);

};

#endif
