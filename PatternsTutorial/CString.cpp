#include "CString.h"
#include <cstdio>

CString::CString() : m_String(NULL) 
{

}
CString::~CString()
{
	if(m_String)
		delete [] m_String;

	m_String = NULL;
}

bool CString::DoInternalCheck(char* _s)
{
	if(!_s)
		return false;

	if(m_String)
		delete [] m_String;

	return true;
}

void CString::Flush()
{
	printf("%#x --> %s\n", this, m_String? m_String : "Error evaluating experession");
}
	
void CString::Set(char* _s)
{
	if(!DoInternalCheck(_s))
		return;

	int _size = strlen(_s);
	m_String = new char[_size+1];
	memcpy(m_String, _s, _size);
	m_String[_size] = '\0';
}