#include "CSingleton.h"
#include "CBasicFactory.h"
#include "CFactoryMaker.h"
#include "CharacterArrayReader.h"
#include "ArrayNumberDecoderBuilder.h"
#include "ArrayCharacterDecoderBuilder.h"
#include "CAdvancedPrototype.h"
#include "CString.h"
#include "objectPool.h"
#include "ChainOfCommandImp1.h"
#include "ChainOfCommandImp2.h"
#include "CReceiver.h"
#include "ICommand.h"
#include "CInvoker.h"
#include "InterpreterBinary.h"
#include "InterpreterContext.h"
#include "InterpreterHex.h"
#include "binaryTreeIterator.h"
#include "binaryTree.h"
#include "CMediator.h"
#include "CFizzObserver.h"
#include "CFazzObserver.h"
#include "CObservedComponent.h"
#include "CGenericObserver.h"
#include "StrategyCompilation.h"
#include "TemplateImplementation.h"
#include "CConcreteVisitor.h"
#include "CShapeCollection.h"
#include "CAsciiAdapter.h"
#include "CRedShape.h"
#include "CBlueShape.h"
#include "CComposite.h"
#include "decorators.h"
#include "CTutorialMeshFactory.h"
#include <iostream>
#include <stdio.h>

class CFunctionPair
{
public:
	void (*function) (void);
	char name[32];

	CFunctionPair(char _name[32], void (*_function) (void)) : function(_function)
	{
		short _size = strlen(_name);
		_size = _size < 32? _size : 32;
		memset(name,'\0',32*sizeof(char));
		memcpy(name, _name, _size);
	}

	~CFunctionPair()
	{
		function = NULL;
	}
};

//---------------------------------
// Creational Design Patterns:
//---------------------------------
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
	// using method factory pattern -->http://www.oodesign.com/factory-method-pattern.html 
	// using the prototype pattern -->http://www.oodesign.com/prototype-pattern.html
	CAdvancedPrototype* prototype = new CAdvancedPrototype(5,"NuevoPrototipo", 0xFF0FF000, true);
	CPrototype* prototypeClone = prototype->Clone();
	prototypeClone->PrintPrototype();
	delete prototype;
	delete prototypeClone;
}

void ObjectPoolPattern()
{
	// using the object pool pattern -->http://www.oodesign.com/object-pool-pattern.html
	// statical declaration for memory management
	CObjectPool<CString> objectPool = CObjectPool<CString>(-1);
	CString* string = objectPool.GetInstance();
	string->Flush();
	string->Set("Hola Mundo");
	objectPool.Release(&string);
	CString* string2 = objectPool.GetInstance();
	string2->Flush();
	string2->Set("Es un nuevo mundo");
	string2->Flush();
	objectPool.Release(&string2);
}

//---------------------------------
// Behavioral Design Patterns:
//---------------------------------
void ChainOfCommandPattern()
{
	// using the builder pattern -->http://www.oodesign.com/chain-of-responsibility-pattern.html
	char string[] = "Esta es una prueva para ver si esto funciona";
	ChainOfCommandImp1 lastPass;
	ChainOfCommandImp2 secondPass = ChainOfCommandImp2(&lastPass);
	ChainOfCommandImp2 firstPass = ChainOfCommandImp2(&secondPass);

	char* pstring = string;
	firstPass.excecuteCommand(&pstring);
}

void CommandPattern()
{
	// using the builder pattern -->http://www.oodesign.com/command-pattern.html
	CInvoker invoker;
	CReceiver reciever = CReceiver("prueva");
	invoker.AddAndExecuteCommand(new ICommand(&reciever, &CReceiver::WriteMessageAsNumbers));
	invoker.AddAndExecuteCommand(new ICommand(&reciever, &CReceiver::WriteMessageAsUpercase));
}

void InterpreterPattern()
{
	// using the interpreter pattern -->http://www.oodesign.com/interpreter-pattern.html
	int val;
	std::cout << "Enter Value\n";
	std::cin >> val;
	std::cout << "processing... \n";

	InterpreterContext context = InterpreterContext(val);
	InterpreterBinary interpreterA;
	InterpreterHex interpreterB;

	printf("Value in binary is: ");
	interpreterA.Interpret(&context);
	context.FlushInterpretedOutput();

	printf("Value in hex is: ");
	interpreterB.Interpret(&context);
	context.FlushInterpretedOutput();
}

void IteratorPattern()
{
	// using the Iterator pattern -->http://www.oodesign.com/iterator-pattern.html
	char input[32];
	std::cout << "Enter 32 char\n";
	std::cin >> input;
	std::cout << "Processing... \n\n";

	CBinaryTree<char>* binaryTree = new CBinaryTree<char>();
	binaryTree->ParseCharArray(input);
	binaryTree->PrintTree();

	delete binaryTree;
}

void MediatorPattern()
{
	// using the mediator pattern -->http://www.oodesign.com/mediator-pattern.html
	CMediator mediator;
	mediator.PrintConcreteCollegue1then2();
	printf("\n\n");
	mediator.PrintConcreteCollegue2then1();
}

void ObserverPattern()
{
	// using the observer pattern -->http://www.oodesign.com/observer-pattern.html
	CObservedComponent observerComponent = CObservedComponent(100);
	CFizzObserver observerA;
	CFazzObserver observerB;
	CGenericObserver observerC = CGenericObserver(5, "Cinco");
	observerComponent.AddObserver(&observerA);
	observerComponent.AddObserver(&observerB);
	observerComponent.AddObserver(&observerC);
	observerComponent.Flush();
}

void StrategyPattern()
{
	// using the strategy pattern -->http://www.oodesign.com/strategy-pattern.html

	// heap
	CAddStrategy add;
	CSubtractStrategy subtract;
	CMultiplyStrategy multiply;

	// stack
	CStrategyContext* context = new CStrategyContext(10, 20, &add);
	
	// Print add
	context->PrintResult();

	// Print Subtraction
	context->ChangeStrategy(&subtract);
	context->PrintResult();

	// Print Multiplication
	context->ChangeStrategy(&multiply);
	context->PrintResult();

	delete context;
}

void TemplatePattern()
{
	// using the template pattern -->http://www.oodesign.com/template-method-pattern.html
	BaseTemplate* story = new TemplateImplementation();

	story->ExecuteTemplate();

	delete story;
}

void VisitorPattern()
{
	// using the visitor pattern -->http://www.oodesign.com/visitor-pattern.html
	CBook book = CBook(3);
	CConcreteVisitor* visitor = new CConcreteVisitor();
	book.Accept(visitor);

	visitor->Flush();
	delete visitor;
}

void NullObjectPattern()
{
	// using the Null Object Pattern -->http://www.oodesign.com/null-object-pattern.html
	CShapeCollection collection;
	int args[6] = {1, 2, 3, 4, 5, 6};
	int count = sizeof(args)/sizeof(*args);
	collection.ProduceShapes(args, count);
	collection.PrintShapes();
} 

//-------------------------------------------
// Structural Patterns
//-------------------------------------------

// Adapter Client
void AdapterPattern()
{
	// using the Adapter Pattern -->http://www.oodesign.com/adapter-pattern.html
	int elements[6] = {48, 51, 53, 55, 58, 57};

	CAsciiAdapter adapter;

	for(int i = 0; i < 6; i++)
	{
		printf(adapter.ReadAsciiNumber(elements[i]));
	}
}

// Briedge Client
void BriedgePattern()
{
	// using the Briedge Pattern -->http://www.oodesign.com/bridge-pattern.html
	IShapedColor* shapedColors[2] = {new CRedShape(0), new CBlueShape(3)};
	int size = sizeof(shapedColors)/sizeof(IShapedColor*);
	for(int i = 0; i < size; ++i)
	{
		shapedColors[i]->Print();
	}
}

// Composite Client
void CompositePattern()
{
	// using the Composite Pattern -->http://www.oodesign.com/composite-pattern.html
	IAbstractFactory* factory1 = CFactoryMaker::createFactory(factoryType::basicFactory);
	IAbstractFactory* factory2 = CFactoryMaker::createFactory(factoryType::extendedFactory);
	
	IShape* shape1 = factory1->CreateShape(1);
	IShape* shape2 = factory1->CreateShape(2);
	IShape* shape3 = factory2->CreateShape(1);
	IShape* shape4 = factory2->CreateShape(2);

	CComposite composite1;
	CComposite* composite2 = new CComposite();

	composite1.Add(shape1);
	composite1.Add(composite2);
	composite1.Add(shape3);
	composite2->Add(shape4);
	composite2->Add(shape2);

	composite1.Draw();
}

// Decorator Client
void DecoratorPattern()
{
	// using the Decorator Pattern -->http://www.oodesign.com/decorator-pattern.html
	CBasicFactory factory;
	IShape* shape1 = (IShape*)new CReflectiveDecorator((IShape*)new CColorDecorator(factory.CreateShape(1), "Red"), true);
	IShape* shape2 = (IShape*)new CColorDecorator(factory.CreateShape(2), "Blue");

	shape1->Draw();
	printf("\n");
	shape2->Draw();

	delete shape1;
	delete shape2;
}

// Flyweight client
void FlyweightPattern()
{
	// using the Flyweight Pattern-->http://www.oodesign.com/flyweight-pattern.html
	CTutorialMeshFactory meshFactory;

	IMesh* meshA	= meshFactory.CreateMeshInstance("meshA");
	IMesh* meshB	= meshFactory.CreateMeshInstance("meshB");
	IMesh* meshC	= meshFactory.CreateMeshInstance("circleMesh");
	IMesh* meshA2	= meshFactory.CreateMeshInstance("meshA");

	meshA->Draw();
	meshB->Draw();
	meshC->Draw();
	meshA2->Draw();

	printf("Same Pointer %s\n", meshA == meshA2? "true" : "false");
}

int main()
{
	CFunctionPair* pairs [] = 
	{
		new CFunctionPair("0.Singleton_Instance",	SingletonInstance), 
		new CFunctionPair("1.Factory_Instance",		FactoryPatternInstance), 
		new CFunctionPair("2.Abstract_Factory",		ExtendedFactoryPatternInstance), 
		new CFunctionPair("3.Builder_Instance",		BuilderPatternInstance),
		new CFunctionPair("4.Prototype_Instance",	PrototypePatternInstance),
		new CFunctionPair("5.Object_Pool_Instance", ObjectPoolPattern),
		new CFunctionPair("6.Chain_of_command",		ChainOfCommandPattern),
		new CFunctionPair("7.Command_Pattern",		CommandPattern),
		new CFunctionPair("8.Interpreter_Pattern",	InterpreterPattern),
		new CFunctionPair("9.Iterator_Pattern",		IteratorPattern),
		new CFunctionPair("10.Mediator_Pattern",	MediatorPattern),
		new CFunctionPair("11.Observer_Pattern",	ObserverPattern),
		new CFunctionPair("12.Strategy_Pattern",	StrategyPattern),
		new CFunctionPair("13.Template_Pattern",	TemplatePattern),
		new CFunctionPair("14.Visitor_Pattern",		VisitorPattern),
		new CFunctionPair("15.Null_Object_Pattern",	NullObjectPattern),
		new CFunctionPair("16.Adapter_Pattern",		AdapterPattern),
		new CFunctionPair("17.Bridge_Pattern",		BriedgePattern),
		new CFunctionPair("18.Composite_Pattern",	CompositePattern),
		new CFunctionPair("19.Decorator_Pattern",	DecoratorPattern),
		new CFunctionPair("20.Flyweight_Pattern",	FlyweightPattern)
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

	// Clean memory
	CFunctionPair** ptr = pairs;

	for(short i = 0; i < _size; i++)
	{
		delete (*ptr);
		ptr++;
	}

	return 0;
}