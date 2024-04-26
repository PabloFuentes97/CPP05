#pragma once
#ifndef BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

#define MIN_GRADE 150
#define MAX_GRADE 1

class	Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat &	operator=(Bureaucrat const & rhs);
		std::string getName() const;
		int			getGrade() const;
		void		incrGrade();
		void		decrGrade();
		void 		testGrade(int grade);
		void		signForm(Form & f);
		class		GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif