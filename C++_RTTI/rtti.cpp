#include <iostream>
using namespace std;

class base
{
public:
	virtual void me() { cout << "I'm base" << endl; }
	// To use RTTI in polymorphism, virtual functions must be included unconditionally.
};

class derived : public base
{
public:
	void me() override { cout << "I'm derived" << endl; }
};

int main()
{
	base* base_obj = new base();
	base* derived_obj = new derived();

	cout << typeid(*base_obj).name() << endl;
	cout << typeid(*derived_obj).name() << endl;

	base_obj->me();
	derived_obj->me();

	if (typeid(derived) == typeid(*derived_obj))
	{
		derived* temp = static_cast<derived*>(derived_obj);
		// No problem
		temp->me();
	}

	delete derived_obj;
	delete base_obj;
}