#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class 	Bureaucrat;

class	PresidentialPardonForm : public AForm{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
		void	execute(Bureaucrat const & executor) const;
		class		OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, PresidentialPardonForm const & rhs);

#endif