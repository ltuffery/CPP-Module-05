#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->isSigned())
	{
		return throw "Form is not signed";
	}
	if (executor.getGrade() > this->getGradeExecute())
	{
		return throw AForm::GradeTooLowException();
	}
	std::string file_name = executor.getName() + "_shrubbery";
	std::ofstream file(file_name.c_str());

	for (int i = 0; i < 2; i++)
	{
		file << "       _-_" << std::endl;
		file << "    /~~   ~~\\" << std::endl;
		file << " /~~         ~~\\" << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  /"<< std::endl;
		file << "   ~  \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;
	}

	file.close();
}
