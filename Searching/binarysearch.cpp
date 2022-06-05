#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target)
{
    int l = 0;
    int r = n-1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int binarySearchRecurs(int arr[], int l, int r, int target)
{
    if(l>r) return -1;

    int mid = l + (r-l)/2;

    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) return binarySearchRecurs(arr,l,mid-1,target);
    else return binarySearchRecurs(arr,mid+1,r,target);
}

int main()
{
    int arr[7] = {2,3,4,5,12,21,67};
    cout<<binarySearch(arr,7,5)<<"\n";
    cout<<binarySearchRecurs(arr,0,6,5)<<"\n";
    return 0;
}