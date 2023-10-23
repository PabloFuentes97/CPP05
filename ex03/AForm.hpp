#pragma once
#ifndef AForm_HPP
#define	AForm_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <exception>

class 	Bureaucrat;

class	AForm{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(AForm &src);
		virtual ~AForm();
		AForm &	operator=(AForm const & rhs);
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void		beSigned(Bureaucrat & b);
		int 		testGrade(int grade) const;
		void		isSigned() const;
		void		testGradeSign(int grade) const; 
		void		testGradeExecute(int grade) const; 
		virtual void	execute(Bureaucrat const & executor) const = 0;
		
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
		class		SignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, AForm const & rhs);

#endif