#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{ //ShrubberyCreationForm
		ShrubberyCreationForm	sF("fichero");
		Bureaucrat				b45("paco", 45);
		Bureaucrat				b149("manuel", 149);

		b45.executeForm(sF);
		b149.signForm(sF);
		b45.signForm(sF);
		b45.executeForm(sF);
	}
	{ //RobotomyRequestForm
		RobotomyRequestForm	rF("pepe");
		Bureaucrat			b70("chema", 70);
		Bureaucrat			b3("josé manuel", 3);

		b70.signForm(rF);
		b70.executeForm(rF);
		b3.executeForm(rF);
	} //PresidentialPardonForm
	{ 
		PresidentialPardonForm	pF("cayo lara");
		Bureaucrat				b50("kiko", 50);
		Bureaucrat				b20("chuso", 20);
		Bureaucrat				b2("francisco javier", 2);

		b50.executeForm(pF);
		b50.signForm(pF);
		b20.signForm(pF);
		b20.executeForm(pF);
		b2.executeForm(pF);
	}
	return (0);
}