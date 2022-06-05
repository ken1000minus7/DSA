#include<iostream>
using namespace std;

template<class T>
class Vector{
    T * arr;
    int sz, cp;
    T temp;

    void creatNewArray()
    {
        cp*= 2;
        T * narr = new T[cp];
        for(int i=0;i<sz;i++)
        {
            narr[i] = arr[i];
        }
        delete []arr;
        arr = narr;
    }

public:

    Vector<T>(int n = 0)
    {
        sz = n;
        cp = max(1,n);
        arr = new T[cp];
    }

    Vector(int n,T def)
    {
        sz = n;
        cp = max(1,n);
        arr = new T[cp];
        for(int i=0;i<sz;i++) arr[i] = def;
    }

    Vector<T>(initializer_list<T> li)
    {
        sz = li.size();
        cp = li.size();
        arr = new T[cp];
        auto it = li.begin();
        for(int i=0;i<sz;i++)
        {
            arr[i] = *it;
            advance(it,1);
        }
    }

    int size()
    {
        return sz;
    }

    int capacity()
    {
        return cp;
    }

    void pushBack(T val)
    {
        if(sz==cp) creatNewArray();
        arr[sz] = val;
        sz++;
    }

    T popBack()
    {
        if(sz==0)
        {
            cout<<"Vector empty\n";
            return temp;
        }
        sz--;
        return arr[sz];
    }

    void pushFront(T val)
    {
        if(sz==cp) creatNewArray();
        sz++;
        for(int i=sz-1;i>0;i--)
        {
            swap(arr[i],arr[i-1]);
        }
        arr[0] = val;
    }

    T popFront()
    {
        if(sz==0)
        {
            cout<<"Vector empty\n";
            return temp;
        }
        sz--;
        for(int i=0;i<sz;i++)
        {
            swap(arr[i],arr[i+1]);
        }
        return arr[sz];
    }

    void insert(int i,T val)
    {
        if(i<0 || i>=sz) 
        {
            cout<<"Invalid index\n";
            return temp;
        }
        if(sz==cp) creatNewArray();
        sz++;
        for(int j=sz-1;j>i;j--)
        {
            arr[j] = arr[j-1];
        }
        arr[i] = val;
    }

    T erase(int i)
    {
        if(i<0 || i>=sz) 
        {
            cout<<"Invalid index\n";
            return temp;
        }
        sz--;
        for(int j=i;j<sz;j++)
        {
            swap(arr[j],arr[j+1]);
        }
        return arr[sz];
    }

    T get(int i)
    {
        if(i<0 || i>=sz) 
        {
            cout<<"Invalid index\n";
            return temp;
        }
        return arr[i];
    }

    void set(int i,T val)
    {
        if(i<0 || i>=sz) 
        {
            cout<<"Invalid index\n";
            return;
        }
        arr[i] = val;
    }

    T& operator [](int i)
    {
        return (i<0 || i>=sz) ? temp : arr[i];
    }

    void operator =(Vector<T> &v)
    {
        sz = v.size();
        cp = v.capacity();
        arr = new T[cp];
        for(int i=0;i<sz;i++)
        {
            arr[i] = v[i];
        }
    }

    bool empty()
    {
        return sz==0;
    }

    void clear()
    {
        sz=0;
    }

    ~Vector()
    {
        delete []arr;
    }

};

int main()
{
    Vector<int> v;
    Vector<int> v1 = v;
    Vector<int> v2 = {1,2,3,4,5};
    v2.pushBack(20);
    for(int i=0;i<50;i++) v2.pushBack(i),cout<<v2.capacity()<<"\n";
    for(int i=0;i<5;i++) v2.pushFront(i),cout<<v2.capacity()<<"\n";
    v2.pushFront(200);
    for(int i=0;i<40;i++) v2.popBack();
    for(int i=0;i<10;i++) v2.popFront();
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<"\n";
    }
    int n;
    cin>>n;
    Vector<Vector<int>> grid(n,Vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}