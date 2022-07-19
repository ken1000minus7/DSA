#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

void buildTree(vector<int> &arr,vector<int> &segTree,int l,int r,int ind)
{
    if(l==r)
    {
        segTree[ind] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    buildTree(arr,segTree,l,mid,2*ind + 1);
    buildTree(arr,segTree,mid+1,r,2*ind+2);
    segTree[ind] = max(segTree[2*ind+1],segTree[2*ind+2]);
}

void update(vector<int> &arr,vector<int> &segTree,int l,int r,int ind,int &i,int &x)
{
    if(l==r)
    {
        segTree[ind] = x;
        arr[l] = x;
        return;
    }
    int mid = l + (r-l)/2;
    if(i<=mid) update(arr,segTree,l,mid,2*ind+1,i,x);
    else update(arr,segTree,mid+1,r,2*ind+2,i,x);
    segTree[ind] = max(segTree[2*ind+1],segTree[2*ind+2]);
}

int query(vector<int> &segTree,int l,int r,int &x,int ind)
{
    if(l==r) return segTree[ind];
    int left = segTree[2*ind+1];
    int right = segTree[2*ind+2];
    int mid = l + (r-l)/2;
    if(left>=x) 
    {
        return query(segTree,l,mid,x,2*ind+1);
    }
    else if(right>=x)
    {
        return query(segTree,mid+1,r,x,2*ind+2);
    }
    else return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> segTree(4*n);
    buildTree(arr,segTree,0,n-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            update(arr,segTree,0,n-1,0,x,y);
        }
        else 
        {
            int x;
            cin>>x;
            cout<<query(segTree,0,n-1,x,0)<<'\n';
        }
    }
    return 0;
}