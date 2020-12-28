/*

    [[nodiscard]] makes warning when return value is dumped

*/

struct [[nodiscard]] X
{
    int i;
};
 
X foo()
{
    return { 42 };
}
 
X x { 42 };
X& foo2() { return x; }
 
[[nodiscard]] int bar()
{
    return 3;
}
 
int main()
{
    // warning: ignoring returned value of type 'X', declared with attribute nodiscard
    foo();
 
    // OK
    foo2();
 
    // warning: ignoring return value of 'int bar()', declared with attribute nodiscard
    auto i = (bar(), 55);
 
    // OK
    (void)bar();
 
    return 0;
}
