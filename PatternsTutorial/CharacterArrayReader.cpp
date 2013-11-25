#include <string>
#include "CharacterArrayReader.h"

CharacterArrayReader::~CharacterArrayReader() 
{
	delete m_pArrayDecoder;
}

char* CharacterArrayReader::getSolutionArray(char* baseArray, int size) 
{
	char* newArray = new char[size+1];
	memcpy(newArray, baseArray, size*sizeof(char));

	char* iterator = newArray;
	for(int i = 0; i < size; i++)
	{
		m_pArrayDecoder->ProcessComponent(iterator);
		iterator++;
	}

	(*iterator) = '\0';

	return newArray;
}