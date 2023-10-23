#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Intern becario;
	std::string forms[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon", "Invalid"};
	srand(time(NULL));
	int	i = rand() % 4;
	std::cout << "Type passed: " << forms[i] << std::endl;
	AForm *form = becario.makeForm(forms[i], "pepe");
	if (!form)
		return (1);
	int grade = rand() % 50;
	std::cout << "Grade: " << grade << std::endl;
	Bureaucrat	b("manuel", grade);
	try
	{
		form->beSigned(b);
		form->execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}