#ifndef CReceiver_h
#define CReceiver_h

#ifdef _WIN32
#pragma once
#endif

class CReceiver 
{
protected:
	char* m_pMessagePointer;
	
public:
	CReceiver(char* message);
	~CReceiver();
	void WriteMessageAsNumbers();
	void WriteMessageAsUpercase();
};

#endif