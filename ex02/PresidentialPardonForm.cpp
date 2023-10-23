#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), _target("default")
{

}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5),
																	 _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : _target(src._target)
						
{
	std::cout << "Copy Constructor" << std::endl;
	//*this = src;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

void	PresidentialPardonForm::action() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream & o, PresidentialPardonForm const & rhs)
{
	o << rhs.getName() << " signed: " << rhs.getSigned()
		<< " grade to sign: " << rhs.getGradeSign()
		<< " grade to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}
