#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

void handleLazy(vector<int> &lazy,vector<int> &segTree,int &l,int &r,int &ind)
{
    segTree[ind] += lazy[ind]*(r-l+1);
    if(l<r)
    {
        lazy[2*ind+1] += lazy[ind];
        lazy[2*ind+2] += lazy[ind];
    }
    lazy[ind]=0;
}

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

void updateRange(vector<int> &lazy,vector<int> &segTree,int l,int r,int ind,int &s,int &e,int &val)
{
    handleLazy(lazy,segTree,l,r,ind);
    if(l>=s && r<=e) 
    {
        lazy[ind]+=val;
        handleLazy(lazy,segTree,l,r,ind);
        return;
    }
    else if(l>e || r<s) return;
    else 
    {
        int mid = l + (r-l)/2;
        updateRange(lazy,segTree,l,mid,2*ind+1,s,e,val);
        updateRange(lazy,segTree,mid+1,r,2*ind+2,s,e,val);
        segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
    }
}

int query(vector<int> &lazy,vector<int> &segTree,int l,int r,int &s,int &e,int ind)
{
    handleLazy(lazy,segTree,l,r,ind);
    if(l>=s && r<=e) return segTree[ind];
    else if(l>e || r<s) return 0;
    else 
    {
        int mid = l + (r-l)/2;
        return query(lazy,segTree,l,mid,s,e,2*ind+1) + query(lazy,segTree,mid+1,r,s,e,2*ind+2);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> segTree(4*n);
    vector<int> lazy(4*n);
    buildTree(arr,segTree,0,n-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            int val;
            cin>>val;
            updateRange(lazy,segTree,0,n-1,0,x,y,val);
        }
        else 
        {
            cout<<query(lazy,segTree,0,n-1,x,y,0)<<'\n';
        }
    }
    return 0;
}