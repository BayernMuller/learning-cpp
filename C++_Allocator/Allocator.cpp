#include <iostream>
using namespace std;

class obj
{
public:
	obj(int a, double b, char c) : mSum(a + b + c)
	{
		cout << "constructor" << endl;
	}

	~obj()
	{
		cout << "destroyer" << endl;
	}

	void PrintSum()
	{
		cout << mSum << endl;
	}

private:
	double mSum;
};

int main()
{
	allocator<obj> alloc;
	obj* pObj = alloc.allocate(sizeof(obj)); // same operatro new() and malloc()
	cout << "allocate" << endl;
	alloc.construct(pObj, 4, 4.5, 'A'); // call constructor (placement new)

	pObj->PrintSum();

	alloc.destroy(pObj); // call destroyer
	alloc.deallocate(pObj, sizeof(obj)); // same delete() and free()
	cout << "deallocate" << endl;
}

/*
	result:

	allocate
	constructor
	73.5
	destroyer
	deallocate
*/