# thread_local  

```C++
#include <iostream>
#include <thread>
#include <mutex>

thread_local unsigned int i = 0;
std::mutex mtx;
 
void ThreadFunc(int nID)
{
    ++i;
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << nID << "-thread : " << i << std::endl;
}
 
int main()
{
    std::thread th1(ThreadFunc, 0), th2(ThreadFunc, 1);
 
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Main thread : " << i << std::endl;
    lock.unlock();
 
    th1.join();
    th2.join();
 
    return 0;
}
```

다음 코드의 결과같이 모든것을 알려준다.

**Main thread : 0**

**0-thread : 1**

**1-thread : 1**

전역 변수에 thread_local 키워드가 추가되면 각각의 thread에 별개로 적용되는 것을 확인할 수 있다..

각각의 thread에서 사용할 변수를 생성할 때 유용하게 사용이 가능하다.