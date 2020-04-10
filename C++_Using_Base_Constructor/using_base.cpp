#include <string>
#include <iostream>
using namespace std;

class ParentClass
{
public:
	ParentClass(const char* str)
	{
		cout << str << endl;
	}
};

class ChildClass : public ParentClass
{
	using ParentClass::ParentClass;
	// Using Parent's Constructor.
public:
	~ChildClass()
	{
		cout << "Destructor" << endl;
	}
};

int main()
{
	ChildClass child("I am child");
	return 0;
}

/*
	result:

	I am child

	It is useful when your class's parent is C++ STL.
	Because STL constructors are very complicated.
*/