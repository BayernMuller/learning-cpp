# static_assert

### assert

<cassert> 헤더를 포함해야 사용 가능하다. assert(bool) 처럼 조건식을 넣고 그 식이 거짓이면 몇번째 줄에서 에러가 났는지 알려주고 프로그램을 종료한다.

```C++
#include "pch.h"
#include <cassert>
#include <iostream>
using namespace std;

int main()
{
	assert(1 > 5);
}
```

### static_assert

```C++
struct obj
{
		char ch;
		int num;
};
```

sizeof obj 는 8이다. 이는 메모리 정렬을 맞추기 위해 컴파일러가 padding을 채우기 때문이다. 하지만 상황에 따라서 Packet의 padding이 제거되어야 할 수도 있다. 이런 경우에 컴파일러 옵션으로 padding이 제거되었는지를 static_assert로 컴파일 타임에 검증하게 할 수 있다.

    static_assert(sizeof(obj) == sizeof(char) + sizeof(int), "padding in Packet");

이제는 만약 pragma pack을 지우거나 혹은 컴파일러 옵션으로 padding을 제거하지 않았다면 static_assert에 걸려서 컴파일 자체가 되지 않을 것이다. 이와 같이 static_assert는 컴파일 시간에 알 수 있는 조건이 충족되지 않을 경우, 컴파일 에러를 발생시켜서 유효성 검증에 실패했음을 알려준다