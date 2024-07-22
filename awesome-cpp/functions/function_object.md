# function objects (since C++11)  

## 정의

함수 객체는 함수 호출 연산자가 정의되어있는 객체이다.
이를 functor 라고도 부른다.

```cpp
class myFunctor
{
 public:
    myFunctor() = default;
    int operator()( const int& lhs, const int& rhs ) const
    {
        return lhs + rhs;
    }
};

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = std::accumulate(v.begin(), v.end(), 0, myFunctor())
};
```

C++은 공통적인 arithmetic and logical operations 을 표현하는 다양한 function object들을 미리 정의해놓았다.

- Arithmetic operations
- Comparisons
- Logical operations
- Bitwise operations

## 예시

function objects는 단독으로 사용하는 것보다, 다른 표준 라이브러리와 함께 사용했을 때 이점이 크다.

```cpp
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = std::accumulate(v.begin(), v.end(), 0);

// accumulate 의 op 인수에 function object를 콜백으로 사용할 수도 있다.
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
```

## 응용

### Transparent operator wrappers (since C++14)

이것은 기존 function object의 specialization인 형태이다.
이것을 사용하면 템플릿 타입 인수를 생략해도 된다.
parameter 와 return type이 알아서 연역(deduced)된다. .

```cpp
// 아래와 같이 multiplies function object의 타입인 int를 생략할 수 있다.
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<>());
```

### Partial function application

- std::bind

## Reference

[Function objects](https://en.cppreference.com/w/cpp/utility/functional)
