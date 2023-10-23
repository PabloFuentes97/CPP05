#pragma once

#ifndef	INTERN_HPP
#define	INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		AForm	*makeForm(std::string type, std::string target) const;
};

#endif