#include <iostream>
using namespace std;

template<class T, int N>
constexpr size_t arr_size(const T(&arr)[N])
{
	// template can receive array size at complile time.
	return N;
}

void print() {} 
// the function called when args is empty.

template<class T, class...Args> 
void print(T&& begin, Args ...args)
{
	cout << begin;
	print(args...); // recursion.
	// print function will constantly 
	// call itself until args is not empty.
}

int main()
{
	print("Bayern is ", "number ", 1, '\n', "Pi is ", 3.141592, '\n');
	int arr[] = {1,2,3};

	int new_arr[arr_size(arr) + 2] = { 1,2,3,4,5 };
	// This syntax is able owing to 
	// arr_size function's return type. (constexpr size_t)
	for (int i : new_arr)
	{
		cout << i << endl;
	}
}
