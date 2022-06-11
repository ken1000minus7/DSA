#include<iostream>
using namespace std;

// elements with i<j are 0, others are non zero
class LowerTriagMatrix{
    int n;
    int *arr; // row major
    int * arrColumn; // column major
    public:
    LowerTriagMatrix(int n) 
    {
        this->n=n;
        arr = new int[(n*(n+1))/2];
        arrColumn = new int[(n*(n+1))/2];
    }

    // row major
    int get(int i,int j)
    {
        if(i<j) return 0;
        // row major formula
        return arr[(i*(i+1))/2+j];
    }
    void set(int i,int j,int val)
    {
        if(i>=j) arr[(i*(i+1))/2+j]=val;
    }

    // column major
    int getColumnMajor(int i,int j)
    {
        if(i<j) return 0;
        // coulmn major formula
        return arrColumn[((n*(n+1))/2 - ((n-j)*(n-j+1))/2 + i-j )];
    }
    void setColumnMajor(int i,int j,int val)
    {
        if(i>=j) arrColumn[((n*(n+1))/2 - ((n-j)*(n-j+1))/2 + i-j )]=val;
    }

    int size()
    {
        return n;
    }

    ~LowerTriagMatrix()
    {
        delete []arr;
        delete []arrColumn;
    }

};

int main()
{
    int n;
    cin>>n;
    LowerTriagMatrix d(n);
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