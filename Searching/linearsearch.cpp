#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target) return i;
    }
    return -1;
}

// improving linear search

// transposition - if element found move it one step to the left
int linearSearch1(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
            if(i>0) swap(arr[i],arr[i-1]);
            return i;
        }
    }
    return -1;
}

// move to front/head - if element found move it to 1st position
int linearSearch2(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
            swap(arr[i],arr[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[7] = {2,3,4,67,21,12,5};
    cout<<linearSearch(arr,7,5)<<"\n";
    cout<<linearSearch1(arr,7,5)<<"\n";
    cout<<linearSearch2(arr,7,5)<<"\n";
    return 0;
}