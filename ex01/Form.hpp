#pragma once
#ifndef FORM_HPP
#define	FORM_HPP


#include <string>
#include <iostream>
#include <exception>

class 	Bureaucrat;

class	Form{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(Form &src);
		~Form();
		Form &	operator=(Form const & rhs);
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void		beSigned(Bureaucrat & b);
		int 		testGrade(int grade);
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

std::ostream &operator<<(std::ostream & o, Form const & rhs);

#endif