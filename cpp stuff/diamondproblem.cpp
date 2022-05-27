#include<iostream>
using namespace std;

// virtual functions, interfaces, virtual inheritance etc are all part of runtime polyphormism

// diamond problem arises with multiple inheritance 
// also called deadly diamond of death 💀
// ambiguity arises when accessing properties of the common super class of the two base classes
// to fix this we use virtual inheritance, if any property of the Parent class is not defined in the two child classes, then using virtual inheritance, the grandchild can indirectly access the properties of Parent class
// it stores vpointer of parent class or something, some complex stuff can ignore

class Parent{
    protected:
    int x;
};

class Child1 : virtual public Parent{

};

class Child2 : virtual public Parent{

};

class GrandChild : public Child1, public Child2{
    public:
    void display()
    {
        cout<<x<<"\n";
    }
};

int main()
{
    GrandChild * gc = new GrandChild();
    gc->display();
    return 0;
}