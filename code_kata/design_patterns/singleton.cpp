#include <cstdio>
#include <mutex>

using namespace std;

class Singleton 
{
public:
    static Singleton &getInstance()
    {
        call_once(Singleton::mOnceFlag, []() 
        {
	    printf("call_once is invoked.\n");
            mInstance.reset( new Singleton() );
        });

        return *(mInstance.get());
    }

    void print()
    {
        printf("Hello world!\n");
    }


private:
    static unique_ptr<Singleton> mInstance;
    static once_flag mOnceFlag;

    Singleton()
    {
	printf("Constructor is created.\n");
    }
    Singleton( const Singleton& singleton ) = delete;
    Singleton &operator=( const Singleton& singleton ) = delete;
};

unique_ptr<Singleton> Singleton::mInstance;
once_flag Singleton::mOnceFlag;

int main()
{
    Singleton::getInstance().print();
    Singleton::getInstance().print();
    Singleton::getInstance().print();
}
