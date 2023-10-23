#pragma once
#ifndef SHRUBERYCREATIONFORM_HPP
#define	SHRUBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class 	Bureaucrat;

class	ShrubberyCreationForm : public AForm{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
		void	action() const;
		class		OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif