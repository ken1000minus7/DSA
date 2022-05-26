#include<iostream>
using namespace std;

// class is a blueprint of an object, object is a real life entity and it is an instance of a class

class Pokemon{
    // by default the members are private in classes but public in structs
    public:

    // data members

    string name;
    string type;
    int weight;
    mutable string lastFunctionCalled;

    // constructor - function which constructs an object, called when an object is created

    Pokemon() {} // no arg default constructor

    // in memory the object contains all its data members and along with that, this which is a pointer to the object itself
    Pokemon(string name, string type,int weight)
    {
        // when accessing the properties of the object itself we use . but if we want to access the properties of the object it points to we use ->
        this->name = name;
        this->type = type;
        this->weight = weight;
    }

    // member functions

    // declaring function as const ensures that no data member will be changed inside this function
    void display() const
    {
        // however, we can change mutable variables even in a const function
        lastFunctionCalled = "display";
        
        cout<<name<<" "<<type<<" "<<weight<<"\n";
    }

    // destructor - function called just when an object is destroyed or removed from memory
    ~Pokemon() {}

};

int main()
{
    // this will call default constructor
    Pokemon p1;

    Pokemon p2("Bulbasaur","Grass",40);

    p2.display();

    // const ensure that value of the variable can't be changed
    const int hi = 10;

    // pointer to a const int, we can't change the value by deferencing, can write int const as well
    const int * p = &hi;
    
    // can change the value like this, but hi variable will still have the same value, very weird behaviour of cpp lol
    int * pp = (int *) &hi;
    *pp = 100;

    // can change value of the memory location but the pointer variable a is now const and can't be reassigned
    int* const a =new int;

    // can't change both
    const int * const aa = new int;

    // if we declare a const object, we can only use const functions of that object since we can't change any data members (obvio)
    const Pokemon p3("Charmander","Fire",40);
    p3.display();

    return 0;
}