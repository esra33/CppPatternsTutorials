#include "CSingleton.h"
#include "CBasicFactory.h"
#include "CFactoryMaker.h"
#include "CharacterArrayReader.h"
#include "ArrayNumberDecoderBuilder.h"
#include "ArrayCharacterDecoderBuilder.h"
#include "CAdvancedPrototype.h"
#include <iostream>
#include <stdio.h>

class CFunctionPair
{
public:
	void (*function) (void);
	char name[32];

	CFunctionPair(char _name[32], void (*_function) (void)) : function(_function)
	{
		memset(name, 0, strlen(name));
		memcpy(name, _name, strlen(_name));
	}

	~CFunctionPair()
	{
		delete []name;
	}
};

void SingletonInstance() 
{
	char* stream = new char[100];
	std::cout << "Enter a message to print\n";
	std::cin >> stream;
	
	// Using the singleton pattern --> http://www.oodesign.com/singleton-pattern.html
	CSingleton::Instance()->PutMessage(stream);
	std::cout << "\n\nThis is the stream\n";
	CSingleton::Instance()->PrintMessage();

	delete [] stream;
}
void FactoryPatternInstance()
{
	// Using the factory pattern --> http://www.oodesign.com/factory-pattern.html
	std::cout << "\nEnter the item id to create\n";
	int factoryID = 0;
	std::cin >> factoryID;
	CBasicFactory baseFactory;

	IShape* currentShape = baseFactory.CreateShape(factoryID);
	if(currentShape) 
		currentShape->Draw();

	delete currentShape;
}
void ExtendedFactoryPatternInstance()
{
	int factoryID = 0;
	IShape* currentShape;
	// using the abstract factory pattern --> http://www.oodesign.com/abstract-factory-pattern.html
	std::cout << "\nEnter the factory id to use\n";
	std::cin >> factoryID;
	IAbstractFactory* currentFactory = CFactoryMaker::createFactory((factoryType)factoryID);

	if(currentFactory == NULL)
	{
		printf("Selected factory is not supported\n");
		return;
	}

	std::cout << "\nEnter the item id to create\n";
	std::cin >> factoryID;
	currentShape = currentFactory->CreateShape(factoryID);
	if(currentShape) 
		currentShape->Draw();
	
	delete currentShape;
}
void BuilderPatternInstance()
{
	// using the builder pattern --> http://www.oodesign.com/builder-pattern.html
	char items []= {0,1,2,3,4,5,6,7,8,9,10,2,4,6,8,10};
	CharacterArrayReader* arrayReader1 = new CharacterArrayReader(new ArrayNumberDecoderBuilder());
	CharacterArrayReader* arrayReader2 = new CharacterArrayReader(new ArrayCharacterDecoderBuilder());

	char* items1 = arrayReader1->getSolutionArray(items, sizeof(items));
	char* items2 = arrayReader2->getSolutionArray(items, sizeof(items));
	printf(items1);
	printf("\n");
	printf(items2);

	delete arrayReader1;
	delete arrayReader2;
	delete [] items1;
	delete [] items2;
}
void PrototypePatternInstance()
{
	CAdvancedPrototype* prototype = new CAdvancedPrototype(5,"NuevoPrototipo", 0xFF0FF000, true);
	CPrototype* prototypeClone = prototype->Clone();
	prototypeClone->PrintPrototype();
	delete prototype;
	delete prototypeClone;
}

int main()
{
	CFunctionPair* pairs [] = 
	{
		new CFunctionPair("0.Singleton_Instance", SingletonInstance), 
		new CFunctionPair("1.Factory_Instance", FactoryPatternInstance), 
		new CFunctionPair("2.Abstract_Factory", ExtendedFactoryPatternInstance), 
		new CFunctionPair("3.Builder_Instance", BuilderPatternInstance),
		new CFunctionPair("4.Prototype_Instance", PrototypePatternInstance)
	};

	short selection = 0;
	const int _size = sizeof(pairs)/sizeof(CFunctionPair*);
	char answer;

	while(selection != -1)
	{
		// select an option
		printf("Make a selection\n");
		for(short i = 0; i < _size; i++)
		{
			printf(pairs[i]->name);
			printf("\n");
		}
		std::cout << "\n";
		std::cin >> selection;
		selection = selection < 0? 0 : selection >= _size? (_size -1) : selection;
		pairs[selection]->function();

		std::cout << "\n\nContiniu Working? Y/N\n";
		std::cin >> answer;
		selection = (answer == 'Y' || answer == 'y')? 0 : -1;
		system("CLS");
	}

	return 0;
}