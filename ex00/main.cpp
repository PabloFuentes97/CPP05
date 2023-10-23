#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	b1("paco", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b2("manuel", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat	b3;
	Bureaucrat	b4("chema", 10);
	Bureaucrat	b5("josé ramón", 0);
	Bureaucrat	b6("federico", 150);

	b3.decrGrade();
	std::cout << b3 << std::endl;
	b4.incrGrade();
	std::cout << b4 << std::endl;
	b5.incrGrade();
	std::cout << b5 << std::endl;
	b6.decrGrade();
	std::cout << b6 << std::endl;
	return (0);
}