# constexpr

기존의 const 보다 훨씬 더 상수성에 충실하며, 컴파일 타임 함수를 이용한 성능 향상을 위해 C++ 11  부터 생긴 예약어.

const 변수와 constexpr 는 차이점이 있다. const 변수의 초기화를 런타임까지 지연시킬 수 있는 반면, constexpr 변수는 반드시 컴파일 타임에 초기화가 되어 있어야 한다.

초기화가 안 되었거나, 상수가 아닌 값으로 초기화 시도시 컴파일이 되지 않는다.

```C++
constexpr int num = 5; // O
const int constant = num; // O
constexpr int const_expr = num + 1; // X
constexpr int const_expr2; // X
```

constexpr을 함수 반환값에 사용할 때는 다음의 제약들이 따른다.

- 가상으로 재정의된 함수가 아니어야 한다.
- 반환값의 타입은 반드시 LiteralType이어야 한다.

함수에 constexpr을 붙일 경우 inline을 암시한다. 컴파일 타임에 평가하기 때문이며, inline 함수들과 같이 컴파일된다.

constexpr의 함수 인자들이 constexpr 규칙에 부합하지 못하는 경우엔 컴파일 타임에 실행되지 못하고 런타임에 실행된다.

```C++
template<typename T, int N>
constexpr int length(const T(&)[N]) 
{
    return N; // 배열을 받아서 배열의 크기 리턴
}

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}
 
int main()
{
    // 4는 리터럴 타입이므로 상수 타임에 컴파일 성공
    constN<factorial(4)> out1;
 
    // ab는 4의 값을 가지지만, 리터럴 타입이 아니므로 컴파일 에러 발생
    // error C2975: 'N': 'constN'의 템플릿 인수가 잘못되었습니다.
		// 컴파일 타임 상수 식이 필요합니다.
    int ab = 4;
    constN<factorial(ab)> out2;
 
    // 리터럴 타입이 아니므로, 이 함수는 런타임에 실행된다.
    // 하지만 정상 동작한다.
    int cd = factorial(ab);
}
```

LiteralType 클래스를 생성할 때 constexpr 생성자를 사용할 수 있다. 이 때의 제약은 다음과 같다.

- 모든 생성자 함수의 매개변수들 역시 LiteralType들이어야 한다.
- 어떤 클래스로부터 상속받지 않아야 한다

**관련 문서**

[https://docs.microsoft.com/ko-kr/cpp/cpp/constexpr-cpp?view=vs-2019](https://docs.microsoft.com/ko-kr/cpp/cpp/constexpr-cpp?view=vs-2019)

[http://sweeper.egloos.com/3147813](http://sweeper.egloos.com/3147813)