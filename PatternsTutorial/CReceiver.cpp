#include "CReceiver.h"
#include <string>
#include <math.h>

#define Min(x,y) x < y? x : y
#define Max(x,y) x > y? x : y

CReceiver::CReceiver(char* message) : m_pMessagePointer(message)
{

}
CReceiver::~CReceiver()
{

}

void CReceiver::WriteMessageAsNumbers()
{
	// char to # --> 49
	int delta = 97, messageSize = strlen(m_pMessagePointer);
	unsigned int final = 0;
	int currDelta;
	for(int i = 0; i < messageSize; i++) 
	{
		currDelta = m_pMessagePointer[i] - delta;
		if(currDelta > 9)
		{
			final = final*100 + currDelta;
		} else {
			final = final*10 + currDelta;
		}
	}

	printf("%u", final);
}
void CReceiver::WriteMessageAsUpercase()
{
	int delta = 32, messageSize = strlen(m_pMessagePointer);
	char* newMessage = new char[messageSize+1];
	memset(newMessage, '\0', sizeof(char)*(messageSize+1));
	for(int i = 0; i < messageSize; i++) 
		newMessage[i] = m_pMessagePointer[i] - delta;

	printf(newMessage);
	delete [] newMessage;
}
