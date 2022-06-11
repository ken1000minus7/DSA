#include<iostream>
using namespace std;

// all elements other than diagonal elements are zero, better to store in 1d array than 2d otherwise a lot of time and space wasted on zeroes
class DiagonalMatrix{
    int n;
    int *arr;

    public:
    DiagonalMatrix(int n) 
    {
        this->n = n;
        arr = new int[n];
    }
    int get(int i,int j)
    {
        if(i==j) return arr[i];
        return 0;
    }
    void set(int i,int j,int val)
    {
        if(i==j) arr[i]=val;
    }
    int size()
    {
        return n;
    }
    ~DiagonalMatrix()
    {
        delete []arr;
    }

};

int main()
{
    int n;
    cin>>n;
    DiagonalMatrix d(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            d.set(i,j,a);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<d.get(i,j)<<" ";
        }
        cout<<"\n";
    }
}