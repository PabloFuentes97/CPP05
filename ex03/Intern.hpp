#pragma once

#ifndef	INTERN_HPP
#define	INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern &src);
		~Intern();
		Intern	&operator=(Intern const &rhs);
		AForm	*makeForm(std::string type, std::string target) const;
};

#endif