#include<iostream>
using namespace std;

// interface or abstract class represents a contract that any class that implements this class must implement all its functions
// we can't create an object of an abstract classs
// abstract class has atleast one pure virtual function
class Base{
    public:
    // pure virtual function
    virtual void display() = 0;
};

class A : public Base{
    public:
    // we can't instantiate an object of this class unless we override all the pure virtual functions in the base class
    void display() override
    {
        cout<<"A\n";
    }
};

class B : public Base{
    public:
    void display() override
    {
        cout<<"B\n";
    }
};

void printStuff(Base * b)
{
    // any class that had implemented Base interface must have implemented all its pure virtual functions so we can call display() without worrying about its implementation
    // so we don't have to wait for a nab programmer to finish their implementation, we can continue our work ezily
    b->display();
}

int main()
{
    A* a = new A();
    B* b = new B();
    printStuff(a);
    printStuff(b);
    return 0;
}