#include<iostream>
using namespace std;

// inheritance - capability of class to inherit properties of another class

// base class - class whose properties are inherited or derived
class Counter{
    // protected can be accessed by derived classes but not outside classes, private can't be accessed by even derived classes
protected:
    int count;

public:
    Counter() : count(0) {}

    Counter(int c) : count(c) {}

    Counter increment()
    {
        count++;
        return *this;
    }

    Counter decrement()
    {
        count--;
        return *this;
    }

    int getCount() const
    {
        return count;
    }

};

// derived class - class which derives the properties of the base class
// example of public inheritance
// makes public members of base class public and protected members will become protected
// in protected inheritance, public and protected members become protected
// in private inheritance, public and protected members become private
// by default, inheritance is private
class DoubleCounter : public Counter{

    public:

    // first the default constructor of the base class will be called and then this will be called
    // we can specify which constructor of the base class to call before calling this
    DoubleCounter() {}

    // we have specified that 2nd constructor of base class will be called before this
    DoubleCounter(int c) : Counter(c) {}

    // function overriding, define function with same name as that in the base class
    DoubleCounter increment()
    {
        count+=2;
        return *this;
    }

    // we can also call functions of the base class like this, we can't use this->decrement(), it will call the function in the derived class and not the base class
    DoubleCounter decrement()
    {
        count--;
        Counter::decrement();
        return *this;
    }
};

// multilevel inheritance
// constructors are called in the order parent to child as child class needs to derive all the properties of its parents before it can define its own properties
// destructors are called in the order child to parent
// size of object includes size of its own properties and also size of its derived properties
// lower sized data member of a class provided more size, this is called padding
// size of data members dependent on compilers
// done for compiler optimization or something idk
class TripleCounter : public DoubleCounter{

};

class Something {
    protected:
    int lol;
};

// multiple inheritance
// constructors of base classes called in the order they r mentioned
class SomeCounter : public Counter,public Something{

};


int main()
{
    DoubleCounter d(1);
    d.increment();
    // we can use getCount even if it is not defined in the derived class
    cout<<d.getCount()<<"\n";
    d.increment();
    d.increment();
    d.decrement();
    cout<<d.getCount()<<"\n";
    return 0;
}