#ifndef CharacterArrayReader_h
#define CharacterArrayReader_h

#ifdef _WIN32
#pragma once
#endif

#include "ArrayDecoderBuilder.h"

class CharacterArrayReader
{
	ArrayDecoderBuilder* m_pArrayDecoder;

public:
	CharacterArrayReader(ArrayDecoderBuilder* arrayDecoder) : m_pArrayDecoder(arrayDecoder) {};
	~CharacterArrayReader();
	char* getSolutionArray(char* baseArray, int size);
};

#endif