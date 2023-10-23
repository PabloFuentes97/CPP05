#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	f1("seguros", 161, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	b2("incendios", 10, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Form	f3;
	Form	f4("robos", 10, 5);
	Form	f5("asesinato", 5, 10);
	std::cout << f3 << std::endl;
	std::cout << f4 << std::endl;
	Bureaucrat	b1("josé ramón", 0);
	Bureaucrat	b2("federico", 30);
	Bureaucrat	b3("manolo", 5);
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	f3.beSigned(b1);
	std::cout << f3 << std::endl;
	try
	{
		f4.beSigned(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	f4.beSigned(b1);
	std::cout << f4 << std::endl;
	b3.signForm(f5);
	b2.signForm(f4);
	return (0);
}