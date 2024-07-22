# C++ Smart Pointer

## Overview

c++ 에서는 힙 메모리를 쉽게 관리할 수 있도록 smart pointer(스마트 포인터)를 제공하고 있다.  
스마트 포인터의 유형은 아래와 같다. (auto_ptr 은 c++11 표준에서 삭제되었음)  

- unique_ptr
- shared_ptr
- weak_ptr
- unique_ptr

## unique_ptr

특정 객체에 대해 하나의 소유자만 존재할 수 있도록 허용하는 포인터.
[std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr)

### unique_ptr 생성 방법

- c++14 이전  
```std::unique_ptr<Foo> mySmartPointer(new Foo());```  

- c++14 이후  
```auto mySmartPointer = std::make_unique<Foo>();```  

make_unique 를 통해 unique_ptr를 생성할 수 있다.(c++14)
꺽쇠 괄호 <> 안에는 자료형의 타입이 명시된다.
소괄호 안에는 해당 객체의 생성을 위한 인수가 들어간다. (ex: 생성자 인수)
포인터 변수를 만들 때, auto 키워드를 사용할 수 있다. (c++14)

배열 생성 방법
```auto mySmartPointerArray = make_unique<int[]>(10)```

### unique_ptr 사용 방법

스마트 포인터는 일반 포인터와 같은 방식으로 사용할 수 있다.

```cpp
mySmartPointer->myFunction();
*(mySmartPointer).myFunction();
```

### unique_ptr 주요 함수

- get: managed object 의 포인터를 반환한다. (만약 소유하고 있는 객체가 없다면 nullptr 반환)
- reset: managed object 를 인수로 전달된 객체로 대체하고, 현재 소유하고 있는 객체는 제거함.
- release: managed object의 소유권을 제거하며, managed object의 포인터를 반환한다.

## shared_ptr

특정 객체에 대해 여러 소유자가 존재할 수 있도록 허용하는 포인터.
[std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr)
[shared_ptr 인스턴스 만들기 및 사용](https://docs.microsoft.com/ko-kr/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-160)

shared_ptr의 객체는 다음과 같은 조건에 의해서 제거된다.
해당 객체를 소유하고 있는 마지막 남은 shared_ptr이 제거될 때
해당 객체를 소유하고 있는 마지막 남은 shared_ptr이 = 나 reset()를 통해 대체될 때
그 외 사용 방법은 unique_ptr과 크게 다르지 않다.

### shared_ptr 생성 방법

- c++ 14 이전  
```std::shared_ptr<Foo> sh2(new Foo{10});```  
- c++ 14 이후  
```auto mySmartPointer = std::make_shared<Foo>();```  

### shared_ptr 사용 방법

unique_ptr와 크게 다르지 않다.

### shared_ptr 주요 함수

- get, reset이 지원된다. (그러나 release는 지원되지 않는다.)
- use_count: managed object를 소유하고 있는 포인터들의 수를 반환한다. (=reference count)

## References

<https://docs.microsoft.com/ko-kr/cpp/cpp/smart-pointers-modern-cpp?view=msvc-160>
smart pointer (cppreference)
