#include<iostream>
using namespace std;

int main()
{
    // Abstract data types have a representation of data and set of operations that can be performed on the data
    
    // contiguous collection of elements of same type grouped under same name
    // static array, size determined at compile time
    int a[5]; // intialized with garbage value
    int b[5] = {1,2,3,4,5}; // intialize with specified values
    int c[5] = {1,2}; // rest values are 0
    int d[5] = {0}; // intialize with all 0s
    int e[] = {1,2}; // size assigned according to no of elements specified
    
    cout<<b[1]<<" "<<1[b]<<" "<<*(b+1)<<"\n";

    int n;
    cin>>n;
    int aa[n]; // size determined at runtime
    int * arr = new int[10]; // array created in heap

    // 2D arrays

    int a1[3][4]; // created in stack
    int aa1[1][1] = {{1}};

    // array of integer pointers containing arrays created in heap, can use variable sizes as well
    int *a2[3];
    for(int i=0;i<3;i++) a2[i] = new int[4];

    // array of integer pointers now made in heap
    int **a3 = new int*[3];
    for(int i=0;i<3;i++) a3[i] = new int[4];

    // Address accessed by compiler using the formula
    // address of a[i] = base + i*w
    // where w is size of data type
    // if index started from 1, we would write i-1 instead of i so one extra operation, that's why 0 index preferred
    
    // 2D arrays stored in memory as a 1D array

    // Row major - 2d array stored in memory row by row (cpp uses row major ig)
    // address of a[i][j] = base + (j + i*m)*w

    // Column major - 2d array stored in memory column by column
    // address of a[i][j] = base + (i + j*n)*w

    // nD arrays a[d1][d2][d3]..d[n], we will access a[i1][i2][i3]..[in]
    // Row major - base + w * submission k from 1 to n( ik * product p from k+1 to n( dp ) )
    // Column major - base + w * submission k from 1 to n( ik * product p from 1 to k-1( dp ) )
    // very high time complexity of O(n^2)
    // can reduce to O(n) using horner's rule
}