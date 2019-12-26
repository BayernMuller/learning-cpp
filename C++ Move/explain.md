# std::move

Move constructor is used to prevent unnecessary copying of objects.

Old object's data will assign at new's and be nullptr. Then we have not copied data.

std::move function just casts l-value reference to r-value reference.
So the function induces calling C++ STL's move constructor.

The object that already moved must not use. Because its data became nullptr.



##### result :

![](result.PNG)