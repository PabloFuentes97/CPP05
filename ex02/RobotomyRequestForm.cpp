#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), _target("default")
{

}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45),
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

void	RobotomyRequestForm::action() const
{
	int	randNum = rand() % 10 + 1;
	switch (randNum % 2)
	{
		case 0:
			std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
			break ;
		case 1:
			std::cout << this->_target << " robotomy failed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & rhs)
{
	o << rhs.getName() << " signed: " << rhs.getSigned()
		<< " grade to sign: " << rhs.getGradeSign()
		<< " grade to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}
