#include<iostream>
using namespace std;

class A {
    public:
    int val;

    A(int v) : val(v) {}

    // at compile time compiler knows that if an instance of A calls hello() then this has to be executed
    // this is static dispatch or early binding
    void hello()
    {
        cout<<"hello A\n";
    }

    // each class maintains a vtable (virtual table) containing entry of all virtual functions of that class which point towards the implementation of that function for that class
    // each class has an extra data member vpointer which is called virtual pointer, it is a pointer to the vtable of the class
    // at runtime, whenever a virtual function is called, compiler will go to the vtable of the class of that object through that object's vpointer and using vtable will locate the corresponding implementation of the function
    // this is dynamic dispatch or late binding
    virtual void display()
    {
        cout<<"A "<<val<<"\n";
    }
};

class B : public A{
    public:

    B(int v) : A(v) {}

    // normal function overriding
    void hello()
    {
        cout<<"hello B\n";
    }

    // overriding virtual functions, override can only be used with virtual functions
    void display() override
    {
        cout<<"B "<<val<<"\n";
    }
};
int main()
{
    // creating object in heap
    B* b = new B(10);
    // inheritance is an is-a relationship so we can do this
    A* a = b;

    // Even though a points to an object of type B, it will execute the A hello() function
    // same problem can arise with destructors as well which results in functionality of only the base class being destroyed and those of the derived class still remaining in the memory
    // can be fixed by using virtual destructors
    a->hello();
    b->hello();

    // Virtual function solves this problem as it accesses vtable through vpointer which is a data member so it has the particular value pointing to the vtable of B
    a->display();
    b->display();
    return 0;
}