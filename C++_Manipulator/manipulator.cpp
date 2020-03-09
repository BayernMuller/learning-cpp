#include <sstream>
#include <iostream>

int main()
{
	std::istringstream iss("A1");

	int value;
	iss >> std::hex >> value; // read hex

	std::cout << std::oct << value << std::endl; // print oct
	std::cout << std::dec << value << std::endl; // print dec
	std::cout << std::hex << value << std::endl; // print hex
}

/*
	std::oct, std::dec, std::hex are actually functions.
	ios_base's opreator>> and operator<< will receive function pointer for parameter.
	then the operators will call the functions.
	

	basic_ostream& __CLR_OR_THIS_CALL operator<<(ios_base&(__cdecl* _Pfn)(ios_base&) ) 
	{
		_Pfn(*this);
		return *this;
	}


	And the functions are called, they will call std::ios_base::setf function.
	It changes the way numbers are input or output.

	inline ios_base& __CLRCALL_OR_CDECL oct(ios_base& _Iosbase) 
	{ 
		_Iosbase.setf(ios_base::oct, ios_base::basefield);
		return _Iosbase;
	}

	code result:

	241
	161
	a1
*/