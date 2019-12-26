#include <vector>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class object
{
	char* str;
public:
	object(const char* format)
	{
		str = new char[strlen(format) + 1];
		strcpy(str, format);
		cout << "Just constructor :\t" << this << endl;
	}

	object(object&& obj) : str(obj.str)
	{
		obj.str = nullptr;
		cout << "Move constructor :\t" << this << endl;
	}

	object(const object& obj)
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
		cout << "Copy constructor :\t" << this << endl;
	}

	void print()
	{
		cout << str << " : " << (void*)str << endl;
	}

	~object()
	{
		if (str)
			delete[] str;
		cout << "Just Destructor :\t" << this << endl;
	}
};


int main()
{
	object obj_1("hello");
	obj_1.print();
	cout << endl;

	object obj_2(std::move(obj_1));
	obj_2.print();
	cout << endl;

	object obj_3(obj_2);
	obj_3.print();
	cout << endl;

	vector<object> v;
	v.push_back(std::move(obj_2));
	v.begin()->print();
	cout << endl;
}