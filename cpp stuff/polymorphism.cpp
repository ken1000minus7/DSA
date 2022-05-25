#include<iostream>
using namespace std;

// polymorphism - having many forms

// function overloading
// functions should differ in number or type of arguments, difference in return type is not enough

void display(int x) 
{
    cout<<x<<"\n";
}

void display(float x)
{
    cout<<x<<"\n";
}

class ComplexNumber{
    public:
    int r,i;
    int *ptr;

    // constructor overloading
    // part of compile time polymorphism also called static or early binding

    ComplexNumber() : r(0), i(0) {} // can write a single line constructor like this

    ComplexNumber(int r,int i)
    {
        this->r = r;
        this->i = i;
    }

    // we can declare function inside the class and define it outside
    int getReal();

    // custom copy constructor, creates a deep copy by assigning a new address to ptr instead of using same address as that of the old object's ptr
    ComplexNumber(ComplexNumber &c)
    {
        this->r = c.r;
        this->i = c.i;
        this->ptr = new int;
        *(this->ptr) = *c.ptr;
    }

    // operator overloading

    // unary operators, prefix operator
    ComplexNumber operator ++()
    {
        ComplexNumber cc(++this->r,++this->i);
        return cc;
    }

    // postfix operator
    ComplexNumber operator ++(int)
    {
        ComplexNumber cc(this->r++,this->i++);
        return cc;
    }

    // addition operator
    ComplexNumber operator +(const ComplexNumber c)
    {
        ComplexNumber cc(r + c.r,i + c.i);
        return cc;
    }

    // assignment operator
    void operator +=(ComplexNumber c)
    {
        r+=c.r;
        i+=c.i;
    }

    // comparison operator
    bool operator==(ComplexNumber c)
    {
        return r==c.r && i==c.i;
    }

    // subscript operator
    int& operator [](int i)
    {
        if(i==0) return this->r;
        if(i==1) return this->i;
        int ok = 0;
        return ok;
    }

    // can't overload following operators
    // . operator
    // * operator
    // ternary operator
    // :: operator
    // sizeof operator
    // typeid operator
    // .* pointer to member operator
};

// defintion of an already declared function, :: is scope resolution operator
int ComplexNumber::getReal()
{
    return this->r;
}

int main()
{
    display(1);
    display(1.1f); // need to write f for float to avoid ambiguity
    display('z'); // type casting done to find a function that works

    ComplexNumber c1(10,20);

    // creates a shallow copy by default, default copy constructor is called that intializes an object using another object, all data members copied\
    // hence any pointer variables will hv the same memory address and so any change in the address of those pointers will reflect in both objects
    // we can create a deep copy by assigning different memory address to the new object by making a new copy constructor
    ComplexNumber c2 = c1;

    c1++;
    ++c2;
    if(c1==c2) cout<<"They are equal\n";
    c1+=c2;
    c1[0] = 92;
    cout<<c1.r<<" "<<c1.i<<" "<<c2.r<<" "<<c2.i<<"\n";
    return 0;
}