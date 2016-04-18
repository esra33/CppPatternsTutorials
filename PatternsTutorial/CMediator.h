#ifndef CMediator_h
#define CMediator_h

#include "IShape.h"

class CMediator
{
	IShape* m_pConcreateCollegue1;
	IShape* m_pConcreateCollegue2;

public:
	CMediator();
	~CMediator();

	void PrintConcreteCollegue1then2();
	void PrintConcreteCollegue2then1();
};

#endif