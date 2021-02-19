#include <iostream>
#include <memory>

template <typename T>
class Auto_ptr{
public:
    Auto_ptr(T* ptr= nullptr):pData(ptr){}
    ~Auto_ptr(){if (pData!= nullptr) delete pData;}
    T& operator*(){return *pData;}
    T operator->(){return pData;}

private:
    T* pData;
};

class Object{
public:
    Object()=default;
    ~Object()=default;
};
int main()
{
    Auto_ptr<Object> myPtr(new Object);
    //Auto_ptr<Object> myPtr2(myPtr) - error (двойное удаление будет)

    std::unique_ptr<Object>(new Object);
    return 0;
}