#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define	ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class 	Bureaucrat;

class	RobotomyRequestForm : public AForm{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
		void	action(void) const;
};

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif