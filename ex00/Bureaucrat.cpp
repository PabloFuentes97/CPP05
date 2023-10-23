#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	testGrade(grade);
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Copy Constructor" << std::endl;
	//*this = src;
}
Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::incrGrade()
{
	try
	{
		testGrade(this->_grade - 1);
		this->_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void	Bureaucrat::decrGrade()
{
	try
	{
		testGrade(this->_grade + 1);
		this->_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
const char*	Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high!");
}
const char*	Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << " grade " << rhs.getGrade();
	return (o);
}

void Bureaucrat::testGrade(int grade)
{
	
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
		
}