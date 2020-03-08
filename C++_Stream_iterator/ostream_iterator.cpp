#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec = { 1,58,8,6,13,2132,23 };
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
}


/*
	std::copy will call std::ostream_iterator<int>'s assignment operator from vec.begin() to vec.end()
	
	Like this:
	ostream_iterator& operator=(const _Ty& _Val) 
	{ 
		*_Myostr << _Val;
		if (_Mydelim) 
		{
			*_Myostr << _Mydelim;
		}
		return *this;
	}

	_Myostr is pointer to ostream.
	the assignment operator prints vector's element and delimiter (On this code, delimiter is " ") if it exists.


	code result:
	
	1 58 8 6 13 2132 23
	
*/