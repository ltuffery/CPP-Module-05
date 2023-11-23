#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm & copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & copy);

		void execute(Bureaucrat const & executor) const;

};

#endif
