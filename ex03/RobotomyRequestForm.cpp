#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequest", 72, 45), _target("default")
{

}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequest", 72, 45),
																	 _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : _target(src._target) //: _signed(src.getSigned())
						
{
	std::cout << "Copy Constructor" << std::endl;
	//*this = src;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

const char * RobotomyRequestForm::RobotomyException:: what() const throw()
{
	return ("Robotomy failed!");
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		int	bGrade = executor.getGrade();
		this->isSigned();
		this->testGradeSign(bGrade);
		this->testGradeExecute(bGrade);
		std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName()
			<< " because " << e.what() << std::endl;
		throw RobotomyRequestForm::RobotomyException();
	}
}

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & rhs)
{
	o << rhs.getName() << " signed: " << rhs.getSigned()
		<< " grade to sign: " << rhs.getGradeSign()
		<< " grade to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}
