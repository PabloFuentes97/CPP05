#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _gradeSign(75), _gradeExec(75), _signed(false)
{
}
AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false),
															 _gradeSign(testGrade(gradeSign)),
															 _gradeExec(testGrade(gradeExec)) 
{
}

AForm::~AForm()
{
}

AForm::AForm(AForm &src) : _name(src.getName()), _signed(src.getSigned()),
						_gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	std::cout << "Copy Constructor" << std::endl;
	//*this = src;
}
AForm &	AForm::operator=(AForm const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_signed = rhs._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getSigned() const
{
	return (this->_signed);
}
	
int			AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int			AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

void		AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::isSigned() const
{
	if (!this->_signed)
		throw AForm::SignedException();
}

int	AForm::testGrade(int grade) const
{
	if (grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	return (grade);
}

void	AForm::testGradeSign(int grade) const
{
	if (grade > this->_gradeSign)
		throw AForm::GradeTooLowException();
}
void	AForm::testGradeExecute(int grade) const
{
	if (grade > this->_gradeExec)
		throw AForm::GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high!");
}
const char*	AForm::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low!");
}

const char*	AForm::SignedException::what() const throw ()
{
	return ("Form isn't signed!");
}

std::ostream &operator<<(std::ostream & o, AForm const & rhs)
{
	o << rhs.getName() << " signed: " << rhs.getSigned()
		<< " grade to sign: " << rhs.getGradeSign()
		<< " grade to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}
