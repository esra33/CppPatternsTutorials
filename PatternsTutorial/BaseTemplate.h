#ifndef	BaseTemplate_h
#define BaseTemplate_h

#ifdef _WIN32
#pragma once
#endif

/*
	It is to be noted that the names on the methods are just examples
	The idea is to have a method that can call a general sequence of algorithms and 
	methods that are latter modified by children classes.
*/
class BaseTemplate 
{
protected:
	virtual void OnPreExecution()=0;
	virtual void OnExecution()=0;
	virtual void OnPostExecution()=0;

public:

	BaseTemplate();
	~BaseTemplate();

	void ExecuteTemplate();

};

#endif