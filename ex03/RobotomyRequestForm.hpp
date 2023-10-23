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
		class RobotomyException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif