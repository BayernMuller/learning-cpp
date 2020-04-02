#include <fstream>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
	std::ifstream file("myfile.txt", ios::binary);
	istreambuf_iterator<char> begin(file), end;
	string str(begin, end);
	cout << str;

	/*
	
	FC Bayern forever number one
	You can call us the champions of the world
	FC Bayern forever number one
	We're much better than the rest

	*/
}