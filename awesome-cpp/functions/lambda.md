# lambda expression (since C++11)

## c++ 람다 표현식의 정의

```cpp
[ captures ] ( params ) specs { body }
```

## 설명

- captures:
  - 콤마로 구분된 캡쳐 블록.
  - 현재 스코프 내에 있는 변수를 지정해서, 람다 바디에서 그 변수들을 사용할 수 있게 한다.
- params:
  - 일반 함수에서 사용되는 것과 같은 매개변수 리스트.
- specs: specifiers, exception, attr and trailing-return-type 의 순서로 구성. (optional)
  - specifiers: mutable, constexpr(c++17) and consteval(c++20)
  - exception: noexcept specifier
  - attr: [Attribute specifier](https://en.cppreference.com/w/cpp/language/attributes)
  - trailing-return-type: '-> ret', 여기서 ret 는 리턴 타입을 일컫는다.
- body:
  - 함수의 몸체

```cpp
auto func1 = [](int i = 0) { return i + 100; };
std::cout << "func1: " << func1() << '\n';
```

실제로 컴파일러는 람다 표현식을 이름 없는 펑터(함수 객체)로 변환한다.
그리고 캡쳐한 변수는 이 펑터의 데이터 멤버가 된다.

### Captures

[]        //no variables defined. Attempting to use any external variables in the lambda is an error.
[x, &y]   //x is captured by value, y is captured by reference
[&]       //any external variable is implicitly captured by reference if used
[=]       //any external variable is implicitly captured by value if used
[&, x]    //x is explicitly captured by value. Other variables will be captured by reference
[=, &z]   //z is explicitly captured by reference. Other variables will be captured by value

### 제네릭 람다(Generic lambda)

만약 auto가 파라미터의 타입으로서 사용된다면, 이 람다를 제네릭 람다(Generic lambda) 라고 부른다.
이때 타입 추론 규칙은 템플릿 인수 추론 방식과 동일하다.

auto isGreaterThan10 = [](auto i){ return i > 10 };

## 예시

```cpp
std::cout << "c: ";
std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
std::cout << '\n';

auto func1 = [](int i = 0) { return i + 100; };
std::cout << "func1: " << func1() << '\n';
```

lambda expression 을 리턴 타입으로 활용

```cpp
function<int<void>> plus10Lambda(int x)
{
    return [x] {return x + 10};
}
```

## Reference

[람다 표현식, lambda expression (since C++11)](https://en.cppreference.com/w/cpp/language/lambda)
