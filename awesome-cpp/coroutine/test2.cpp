#include <iostream> 
#include <coroutine> 

class Task 
{ 
public: 
    // 규칙 1. C++에서 정의된 규칙을 구현한 promise_type 이라는 이름의 타입이 정의되어야 한다. 
    struct promise_type 
    { 
        Task get_return_object() 
        { 
            return Task{ std::coroutine_handle<promise_type>::from_promise(*this) }; 
        } 
        auto initial_suspend() { return std::suspend_always{}; } 
        auto return_void() { return std::suspend_never{}; } 
        auto final_suspend() { return std::suspend_always{}; } 
        void unhandled_exception() { std::exit(1); } 
    }; 
    // 규칙 2. std::coroutine_handle<promise_type> 타입의 멤버 변수가 있어야 한다. 
    std::coroutine_handle<promise_type> co_handler; 
    // 규칙 3. std::coroutine_handle<promise_type> 을 인자로 받아 멤버 변수를 초기화 하는 생성자가 있어야 한다. 
    Task(std::coroutine_handle<promise_type> handler) : co_handler(handler)
    {
    } 
    // 규칙 4. 소멸자에서 std::coroutine_handle<promise_type> 타입의 코루틴 핸들러 멤버 변수를 해제 해야 한다. 
    ~Task() 
    { 
        if (true == (bool)co_handler) 
        { 
            co_handler.destroy(); 
        } 
    } 
}; 

Task foo() 
{
    std::cout << "foo 1" << std::endl; 
    co_await std::suspend_always{}; 
    std::cout << "foo 2" << std::endl; 
} 

int main()
{ 
    Task task = foo(); 
    std::cout << "\t main 1" << std::endl; 
    task.co_handler.resume(); 
    std::cout << "\t main 2" << std::endl; 
    task.co_handler.resume(); 
}
