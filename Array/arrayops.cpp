#include<iostream>
using namespace std;

void reverseArray(int * arr, int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void leftShift(int * arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1] = 0;
}

void leftRotate(int * arr,int n)
{
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1] = temp;
}

int* merge(int * a1,int n,int * a2, int m)
{
    int *a3 = new int[n+m];
    int i=0,j=0,k=0;

    while(i<n && j<m)
    {
        if(a1[i]<a2[j])
        {
            a3[k++] = a1[i++];
        }
        else
        {
            a3[k++] = a2[j++];
        }
    }

    while(i<n)
    {
        a3[k++] = a1[i++];
    }

    while(j<m)
    {
        a3[k++] = a2[j++];
    }

    return a3;
}

// can improve by using merge algo if both array are sorted
int * unionArray(int * a1,int n,int * a2, int m)
{
    int *a3 = new int[n+m];
    int k=0;
    for(int i=0;i<n;i++)
    {
        a3[k++] = a1[i];
    }
    for(int i=0;i<m;i++)
    {
        bool found = false;
        for(int j=0;j<n;j++)
        {
            if(a2[i]==a1[j])
            {
                found = true;
                break;
            }
        }
        if(!found) a3[k++] = a2[i];
    }
    return a3;
}

void printArray(int * arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    reverseArray(arr,n);
    printArray(arr,n);
    leftShift(arr,n);
    printArray(arr,n);
    leftRotate(arr,n);
    printArray(arr,n);
    int * a1 = new int[5]{1,3,12,20,22};
    int * a2 = new int[6]{2,3,7,20,11,23};
    int * a3 = merge(a1,5,a2,6);
    int * a4 = unionArray(a1,5,a2,6);
    printArray(a3,11);
    printArray(a4,11);
}