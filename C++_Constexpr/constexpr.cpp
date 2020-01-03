#include <iostream>
using namespace std;

constexpr int fac(int n)
{
	int result = 1;
	for (; n > 1; n--)
	{
		result *= n;
	}
	return result;
}


int main()
{
	int number = 3;
	int arr[fac(3)] = {0,}; // OK, fac(3)'s value is decided at compile time.
	int arr2[fac(number)]; // Error, number is not a constant.
	
	number = 5;
	int five_fac = fac(number); // OK, but fac(number) will run at runtime.
	constexpr int nVal = number; // Error, nVal must be a constant.
	constexpr int nVal2 = 123; // Ok
}