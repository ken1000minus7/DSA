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

    void display()
    {
        cout<<name<<" "<<type<<" "<<weight<<"\n";
    }

};

int main()
{
    // this will call default constructor
    Pokemon p1;

    Pokemon p2("Bulbasaur","Grass",40);

    p2.display();

    return 0;
}