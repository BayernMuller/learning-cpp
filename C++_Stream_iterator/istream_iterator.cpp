#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	istringstream iss("Bayern   Munich  Forever     number 1");

	istream_iterator<string> begin(iss);
	istream_iterator<string> end;

	vector<string> vec(begin, end);
	copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n"));
}

/*
	std::vector's constructor will copy from begin to end by calling std::istream_iterator<string>'s operator++.
	
	istream_iterator& operator++() 
	{
		_Getval();
		return *this;
	}

	then the operator calls std::istream_iterator<string>::_Getval()
	
	void _Getval() 
	{
		if (_Myistr && !(*_Myistr >> _Myval)) 
		{
			_Myistr = nullptr;
		}
	}

	_Getval will get next value by calling std::istream's operator>>
	This is principle of copying from std::istream to std::vector.

	code result:

	Bayern
	Munich
	Forever
	number
	1
*/