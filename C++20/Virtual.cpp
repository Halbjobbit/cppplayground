#include <string>
#include <iostream>

struct A
{
    std::string toString()
    {
        return "A";
    }
};

struct Base
{
    virtual std::string toString()
    {
        return "Base";
    }
};

struct B : public Base
{
    std::string toString() override
    {
        return "B";
    }
};

template<typename T>
concept Stringable = requires(T t)
{
    t.toString();
};

void RealFoo(Stringable auto s)
{
    std::cout << s.toString() << '\n';
}

void VirtualFoo(Base b)
{
    std::cout << b.toString() << '\n';
}

int main()
{
    for(size_t i = 0; i < 1000000; i++)
    {
        RealFoo(A());
    }
    return 0;
}
