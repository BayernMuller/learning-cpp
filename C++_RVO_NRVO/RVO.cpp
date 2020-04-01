#include <string>
#include <iostream>
using namespace std;

class object
{
public:
	object(const object& obj) : mIdentifier(obj.mIdentifier)
	{
		cout << mIdentifier << " Copy Constructor" << endl;
	}

	object(object&& obj) : mIdentifier(obj.mIdentifier)
	{
		cout << mIdentifier << " Move Constructor" << endl;
	}

	object(int identifier) : mIdentifier(identifier)
	{
		cout << mIdentifier << " Constructor" << endl;
	}

	void print()
	{
		cout << mIdentifier << " is here" << endl;
	}

	~object()
	{
		cout << mIdentifier << " Destructor" << endl;
	}

private:
	int mIdentifier;
};

object GetObject(int num)
{
	return object(num); // RVO
}

int main()
{
	object obj{ GetObject(5) };
	obj.print();

	/* result :
	
	5 Constructor
	5 is here
	5 Destructor

	*/
}