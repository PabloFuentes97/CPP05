#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _gradeSign(75), _gradeExec(75), _signed(false)
{
}
Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false),
															 _gradeSign(testGrade(gradeSign)),
															 _gradeExec(testGrade(gradeExec)) 
{
}

Form::~Form()
{
}

Form::Form(Form &src) : _name(src.getName()), _signed(src.getSigned()),
						_gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	std::cout << "Copy Constructor" << std::endl;
	//*this = src;
}
Form &	Form::operator=(Form const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_signed = rhs._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool		Form::getSigned() const
{
	return (this->_signed);
}
	
int			Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int			Form::getGradeExec() const
{
	return (this->_gradeExec);
}

void		Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high!");
}
const char*	Form::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream & o, Form const & rhs)
{
	o << rhs.getName() << " signed: " << rhs.getSigned()
		<< " grade to sign: " << rhs.getGradeSign()
		<< " grade to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}

int	Form::testGrade(int grade)
{
	if (grade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Form::GradeTooLowException();
	return (grade);
}