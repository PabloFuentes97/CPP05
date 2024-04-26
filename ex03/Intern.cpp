#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}
Intern::Intern(Intern &src)
{
	static_cast<void>(src);
}
Intern::~Intern()
{

}
Intern	&Intern::operator=(Intern const &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

AForm	*Intern::makeForm(std::string type, std::string target) const
{
	const char	*names[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	for (int i = 0; i < 3; i++){
		if (!type.compare(names[i]))
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		} }
	std::cout << "No form has target name!" << std::endl;
	return (NULL);
}
