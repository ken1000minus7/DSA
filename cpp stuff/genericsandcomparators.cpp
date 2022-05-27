#include<iostream>
#include<algorithm>
using namespace std;

class Person{
    public:
    int age;
    string name;

    Person(string name,int age) : name(name) , age(age) {}

    void display() const
    {
        cout<<name<<" "<<age<<"\n";
    }
};

// instead of overloading a function for every different type, we can use generics
// we create a function template which on runtime will be used to create the corresponding function based on the datatype passed to it
template<class T>
T display(T d)
{
    cout<<d<<"\n";
}

// same thing can be done for classes
template<class T>
class Holder{
    T d;
    public:
    Holder(T d) : d(d) {}

    T get() const
    {
        return d;
    }

    void set(T a);
};

// can define functions outside like this
template<class LOL>
void Holder<LOL>::set(LOL a)
{
    d=a;
}

int main()
{
    // comaparators are functions used to compare two objects as objects can't be directly compared using just the comparison operators
    // can also implement comparisn based on multiple factors
    Person p1("hi",48);
    Person p2("blob",50);
    Person p3("sadge",22);
    Person arr[] = {p1,p2,p3};

    // sort function used to sort arrays and all, we can directly pass arrays containing primitive data types but for objects we need to pass along a comparator function
    sort(arr,arr+3,[](Person &c1,Person &c2){
        // This function should return true if c1 < c2, that is, c1 should appear before c2. Sorting one with this sort function is unstable
        return c1.age<c2.age;
    });
    for(Person i : arr) i.display();

    // can call same function even without overloading
    int a =10;
    double aa = 10.32;
    display(a);
    display(aa);

    Holder<Person> h(p1);
    return 0;
}