#include<iostream>
using namespace std;

// linear recursions
// Tail recursion, recursive call is last statement in the function, better to use loop than this
void print(int n)
{
    if(n<=0) return;
    cout<<n<<"\n";
    print(n-1);
}

// Head recursion, recursive call is first statement in the function
void print2(int n)
{
    if(n<=0) return;
    print(n-1);
    cout<<n<<"\n";
}

// Tree recursion, more than one recursive call in the function
void print3(int n)
{
    if(n<=0) return;
    print(n-1);
    print(n-1);
    cout<<n<<"\n";
}

// Indirect recursion, function calls another function that calls itself

void b(int n);

void a(int n)
{
    if(n<=0) return;
    b(n-1);
}

void b(int n)
{
    if(n<=0) return;
    a(n-1);
}

// Nested recursion, recursive call in argument of recursive call
int hello(int n)
{
    if(n<=0) return 0;
    return hello(hello(n-1));
}

int sumNNatural(int n)
{
    if(n<=0) return 0;
    return n + sumNNatural(n-1);
}

int factorial(int n)
{
    if(n<=0) return 1;
    return n*factorial(n-1);
}

int power(int n,int m)
{
    if(m<=0) return 1;
    return n*power(n,m-1);
}

int powerBetter(int n,int m)
{
    if(m<=0) return 1;
    if(m%2==0) return powerBetter(n*n,m/2);
    return n*powerBetter(n*n,(m-1)/2);
}

double taylor(int x,int i,int n)
{
    if(i>=n) return 0;
    return (double)powerBetter(x,i) / factorial(i) + taylor(x,i+1,n);
}

double taylorBetter(int x,int i,int n)
{
    if(i>=n) return 1;
    return 1 + (double)(x*taylorBetter(x,i+1,n))/(i+1);
}

double expp(int x)
{
    return taylorBetter(x,0,10);
}

// excessive recursion, for same parameter multiple recursion calls are made, can improve with memoization
int fibo(int n)
{
    if(n<=1) return n;
    return fibo(n-1) + fibo(n-2);
}

int ncr(int n,int r)
{
    if(r%n==0) return 1;
    return ncr(n-1,r-1) + ncr(n-1,r);
}

int main()
{
    cout<<sumNNatural(6)<<"\n";
    cout<<factorial(6)<<"\n";
    cout<<power(6,3)<<" "<<powerBetter(6,3)<<"\n";
    cout<<expp(1)<<"\n";
    cout<<fibo(5)<<"\n";
    cout<<ncr(6,3)<<"\n";
    return 0;
}