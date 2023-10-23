#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreation", 145, 137), _target("default")
{

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreation", 145, 137),
																	 _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : _target(src._target) //: _signed(src.getSigned())
						
{
	std::cout << "Copy Constructor" << std::endl;
	//*this = src;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

const char * ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return ("Couldn't open file");
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	int	bGrade = executor.getGrade();
	this->isSigned();
	this->testGradeSign(bGrade);
	this->testGradeExecute(bGrade);
	std::string	file = this->_target + "_shrubbery";
	std::ofstream	Write(file, std::ios::out | std::ios::trunc);
	if (!Write.is_open())
		throw ShrubberyCreationForm::OpenFileException();
	Write << "arbol jaja";
}

std::ostream &operator<<(std::ostream & o, ShrubberyCreationForm const & rhs)
{
	o << rhs.getName() << " signed: " << rhs.getSigned()
		<< " grade to sign: " << rhs.getGradeSign()
		<< " grade to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}
