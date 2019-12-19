#include <iostream>
using namespace std;

unsigned long long operator "" _square(unsigned long long n)
{
	return n * n;
}

unsigned long long operator "" _fac(unsigned long long n)
{
	int fac = 1;
	for (int i = 2; i <= n; i++)
		fac *= i;
	return fac;
}

char operator "" _upper(char ch)
{
	return ('a' <= ch && ch <= 'z') ? ch - 'a' + 'A' : ch;
}

void operator "" _out(const char* str, size_t)
{	// the literal operator function that takes parameter
	// with const char* must include size_t parameter.	
	cout << str << endl;
}

// Literal Template Function
template<char...Cs> char* operator "" _toA()
{
	// sizeof...(sth) : number of sth's element
	char* str = new char[sizeof...(Cs) + 1]{ '\0', };
	// Memory allocate and initialization
	char* point = str;
	for (auto i : { Cs... }) // Parameter Pack to Initializer_list
		*point++ = i;
	return str;
}

int main()
{
	cout << 14_square << endl;
	cout << 'a'_upper << endl;
	cout << 5_fac << endl;
	"FC Bayern is the best"_out;

	char* str = 20191219_toA;
	cout << str << endl;
	delete[] str;
}
