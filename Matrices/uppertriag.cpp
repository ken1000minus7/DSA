#include<iostream>
using namespace std;

// elements with i>j are 0, others are non zero
class UpperTriagMatrix{
    int n;
    int *arr; // row major
    int * arrColumn; // column major
    public:
    UpperTriagMatrix(int n) 
    {
        this->n=n;
        arr = new int[(n*(n+1))/2];
        arrColumn = new int[(n*(n+1))/2];
    }

    // row major
    int get(int i,int j)
    {
        if(i>j) return 0;
        // row major formula
        return arr[((n*(n+1))/2 - ((n-i)*(n-i+1))/2 + j-i )];
    }
    void set(int i,int j,int val)
    {
        if(i<=j) arr[((n*(n+1))/2 - ((n-i)*(n-i+1))/2 + j-i )]=val;
    }

    // column major
    int getColumnMajor(int i,int j)
    {
        if(i>j) return 0;
        // coulmn major formula
        return arrColumn[(j*(j+1))/2+i];
    }
    void setColumnMajor(int i,int j,int val)
    {
        if(i<=j) arrColumn[(j*(j+1))/2+i]=val;
    }

    int size()
    {
        return n;
    }

    ~UpperTriagMatrix()
    {
        delete []arr;
        delete []arrColumn;
    }

};

int main()
{
    int n;
    cin>>n;
    UpperTriagMatrix d(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            d.set(i,j,a);
            d.setColumnMajor(i,j,a);
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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<d.getColumnMajor(i,j)<<" ";
        }
        cout<<"\n";
    }
}   