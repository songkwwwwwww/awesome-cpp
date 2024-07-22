# std::fuction (since C++11)

## std::function 의 정의

```cpp
template< class R, class... Args >
class function<R(Args...)>;
```

## 설명

위 정의에서 R 은 리턴 타입이고, ArgTypes는 각각을 콤마로 구분한 매개변수의 타입 목록이다.

클래스 템플릿인 std::function 은 general-purpose polymorphic function wrapper 라고 불린다.
std::function 객체는 어떤 호출 가능한 어떠한 대상이든 취급할 수 있다.
호출 가능한 대상은 일반적으로 다음과 같다.

- functions
- function objects
- lambda expressions
- etc

## 예시

```cpp
void print_num(int i)
{
    std::cout << i << '\n';
}

int main()
{
    std::function<void(int)> f = print_num;
    f(1000);
}
```

std::function은 특히나 아래와 같은 상황에서 유용하게 쓰일 수 있다.

- 콜백을 클래스의 멤버 변수에 저장해야할 때
- 함수 포인터를 매개변수로 받아야 할 때

뿐만 아니라 콜백 매개변수로 std::function 을 사용하지 않고, 다음과 같이 함수 템플릿으로 만들 수도 있다.

```cpp
template <typename F>
void processTemplate(const vector<int>& vec, F f)
{
    for( auto& i : vec )
    {
        f(i);
    }
}
```

## Reference

[https://en.cppreference.com/w/cpp/utility/functional/function](https://en.cppreference.com/w/cpp/utility/functional/function)
