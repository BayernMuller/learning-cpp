# C++ Literal Operator Function

In C++, There are means of assistances for expressing data types, Literal.

```
float : f
bin : 0b
oct : 0
hex : 0x
wchar_t : L
unicode : u8 / u / U
raw string : R
```



We can define our Literal. And it's called **"User defined Literal"**.

```C++
ReturnType operator "" _a(unsigned long long int);
ReturnType operator "" _b(long double);
ReturnType operator "" _c(char);
ReturnType operator "" _d(wchar_t);
ReturnType operator "" _e(char16_t);
ReturnType operator "" _f(char32_t);
ReturnType operator "" _g(const char*, size_t);
ReturnType operator "" _h(const wchar_t*, size_t);
ReturnType operator "" _i(const char16_t*, size_t);
ReturnType operator "" _g(const char32_t*, size_t);
ReturnType operator "" _r(const char*);
template<char...> ReturnType operator "" _t();
```



https://docs.microsoft.com/ko-kr/cpp/cpp/user-defined-literals-cpp?view=vs-2019

