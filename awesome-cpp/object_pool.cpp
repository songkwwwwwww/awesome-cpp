#include <iostream>
#include <memory>
#include <queue>

template <typename T>
class ObjectPool
{
public:
    ObjectPool() = default;
    virtual ~ObjectPool() = default;

    ObjectPool(const ObjectPool<T>& src) = delete;
    ObjectPool<T>& operator=(const ObjectPool<T>& rhs) = delete;

    using Object = std::shared_ptr<T>;
    Object acquireObject();

private:
    std::queue<std::unique_ptr<T>> mFreeList;
};

template <typename T>
typename ObjectPool<T>::Object ObjectPool<T>::acquireObject()
{
    if(mFreeList.empty())
    {
        mFreeList.emplace(std::make_unique<T>());
    }

    std::unique_ptr<T> obj(std::move(mFreeList.front()));
    mFreeList.pop();

    Object smartObject(obj.release(), [this](T* t) { mFreeList.emplace(t); });

    return smartObject;
}

class ExpensiveObject
{
public:
    ExpensiveObject() {}
    virtual ~ExpensiveObject() = default;

private:
    // data member
}

// ObjectPool<ExpensiveObject>::Object

int main()
{
    ObjectPool<>
}