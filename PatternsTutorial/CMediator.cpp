#include "CMediator.h"
#include "CBasicFactory.h"
#include "CCircle.h"
#include "CSquare.h"

CMediator::CMediator()
{
	CBasicFactory factory;
	m_pConcreateCollegue1 = factory.CreateShape(CCircle::GetID());
	m_pConcreateCollegue2 = factory.CreateShape(CSquare::GetID());
}
CMediator::~CMediator()
{
	if(m_pConcreateCollegue1 != NULL)
	{
		delete m_pConcreateCollegue1;
		m_pConcreateCollegue1 = NULL;
	}
	if(m_pConcreateCollegue2 != NULL)
	{
		delete m_pConcreateCollegue2;
		m_pConcreateCollegue2 = NULL;
	}
}

void CMediator::PrintConcreteCollegue1then2()
{
	m_pConcreateCollegue1->Draw();
	m_pConcreateCollegue2->Draw();
}
void CMediator::PrintConcreteCollegue2then1()
{
	m_pConcreateCollegue2->Draw();
	m_pConcreateCollegue1->Draw();
}