#ifndef	TemplateImplementation_h
#define TemplateImplementation_h

#ifdef _WIN32
#pragma once
#endif

#include "BaseTemplate.h"

/*
	It is to be noted that the names on the methods are just examples
	The idea is to have a method that can call a general sequence of algorithms and 
	methods that are latter modified by children classes.
*/
class TemplateImplementation : public BaseTemplate 
{
protected:
	void OnPreExecution();
	void OnExecution();
	void OnPostExecution();

public:

	TemplateImplementation();
	~TemplateImplementation();
};

#endif