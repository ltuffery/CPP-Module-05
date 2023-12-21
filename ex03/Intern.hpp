#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern &operator=(const Intern &intern);

		AForm *makeForm(const std::string &name, const std::string &target);

};

#endif
