#include<iostream>
using namespace std;

void hello()
{
    cout<<"Learning function pointer hehe\n";
}

void pp(int x,int y)
{
    cout<<(x+y)<<" ";
}

void printSum(int arr[],int n,void(*print)(int,int))
{
    // We can decide where to use the function obtained as argument
    for(int i=0;i<n;i++)
    {
        print(arr[i],2);
    }
    cout<<"\n";
}

int main()
{
    // memory bucket gone when stackframe is removed but a bucket created in heap always remains there unless manually removed

    // can create using new, it returns a pointer

    int * p = new int(10); // intialized with 10

    // can create array like this

    int * arr = new int[10];

    // intialize array with all zeros

    int * z = new int[10]();

    // 2d array, we create a primary array of pointers, the pointers contain address of the secondary arrays

    int ** mat = new int*[10];
    for(int i=0;i<10;i++) mat[i] = new int[5]; // 10x5 2d array created

    // add nothrow, ensures that if heap full then we don't get bad alloc runtime exception, instead null is returned

    // int * pp = new int(nothrow)(10);

    // Function pointer, contains address of function but *ptr will not give us address of function as function is not stored in stack or heap
    // it will give us lvalue denoting that it is a function pointer

    void(*ptr)() = hello; // can use &hello as well, doesn't matter
    ptr();

    // Can be used to pass the function as argument to another function, used as callbacks

    int ar[10] = {1,2,3,4,5,6,7,8,9,10};

    printSum(ar,10,pp);

    // Can use lambda expression instead of defining a function separately, we write the function directly while passing it as argument
    // Can pass any local variables in the square brackets (captures) if the function uses them

    printSum(ar,10,[](int x,int y){
        cout<<(x+y)<<" ";
    });

    // Smart pointers - normal pointers don't free the space automatically, we need to use delete or free. Smart pointer automatically free the space in heap when no longer needed
    
    // Unique pointers - only one pointer allowed to point to the object

    unique_ptr<int> ptr1 = make_unique<int>(9);

    // Shared pointers - more than one pointer can point to same pointer, the maintain reference count of each pointer, when reference count becomes 0 , object is destroyed
    
    shared_ptr<int> ptr2 = make_shared<int>(3);
    shared_ptr<int> ptr3 = ptr2;
    cout<<ptr2.use_count()<<"\n"; // gives no of references

    // Weak pointers - point to an object pointed by a shared pointer, not allowed to access the obejct, only check whether object is still in memory or was manually deleted. Helps in solving dangling pointer problem

    weak_ptr<int> ptw(ptr2);
    cout<<ptw.expired()<<"\n";

    return 0;
}