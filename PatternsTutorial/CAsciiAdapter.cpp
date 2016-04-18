#include "CAsciiAdapter.h"

CAsciiAdapter::CAsciiAdapter()
{
	m_pAdaptee = new CAsciiNumber();
}
CAsciiAdapter::~CAsciiAdapter()
{
	delete m_pAdaptee;
}
const char* CAsciiAdapter::ReadAsciiNumber(int asciiValue)
{
	int i = m_pAdaptee->ReadAsciiNumber(asciiValue);

	switch(i)
	{
	case 0:
		return "Zero\n";
	case 1:
		return "One\n";
	case 2:
		return "Two\n";
	case 3: 
		return "Three\n";
	case 4:
		return "Four\n";
	case 5:
		return "Five\n";
	case 6:
		return "Six\n";
	case 7:
		return "Seven\n";
	case 8:
		return "Eight\n";
	case 9:
		return "Nine\n";
	}

	return "Error_Code_Unknown\n";
}