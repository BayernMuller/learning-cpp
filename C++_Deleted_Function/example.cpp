class obj
{
public:
    obj(const obj&) = delete;
    // deleted default copy constructor.

    obj& operator=(const obj&) = delete;
    // deleted default copy assignment operator.
};

bool func(int number);
bool func(double) = delete;

template<typename T>
void processPointer(T* ptr);

template<> void processPointer<void>(void*) = delete; 

int main()
{
    func(7); // able.
    func('a'); // able.
    func(3.5); // unable. error.
}