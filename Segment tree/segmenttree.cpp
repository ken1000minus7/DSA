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
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
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
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
}

int query(vector<int> &segTree,int l,int r,int &s,int &e,int ind)
{
    if(l>=s && r<=e) return segTree[ind];
    else if(l>e || r<s) return 0;
    else 
    {
        int mid = l + (r-l)/2;
        return query(segTree,l,mid,s,e,2*ind+1) + query(segTree,mid+1,r,s,e,2*ind+2);
    }
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
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            update(arr,segTree,0,n-1,0,x,y);
        }
        else 
        {
            cout<<query(segTree,0,n-1,x,y,0)<<'\n';
        }
    }
    return 0;
}