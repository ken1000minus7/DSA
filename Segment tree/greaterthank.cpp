#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

void buildTree(vector<ll> &arr,vector<vector<ll>> &segTree,int l,int r,int ind)
{
    if(l==r)
    {
        segTree[ind] = {arr[l]};
        return;
    }
    int mid = l + (r-l)/2;
    buildTree(arr,segTree,l,mid,2*ind + 1);
    buildTree(arr,segTree,mid+1,r,2*ind+2);
    auto left = segTree[2*ind+1];
    auto right = segTree[2*ind+2];
    int i=0,j=0;
    vector<ll> ans;
    while(i<left.size() || j<right.size())
    {
        if(j>=right.size() || (i<left.size() && left[i]<right[j]))
        {
            ans.push_back(left[i]);
            i++;
        }
        else
        {
            ans.push_back(right[j]);
            j++;
        }
    }
    segTree[ind] = ans;
}

int query(vector<vector<ll>> &segTree,int l,int r,int &s,int &e,int ind,int &k)
{
    if(l>=s && r<=e)
    {
        int ans = r+1;
        int orgr = r+1;
        int orgl = l;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(segTree[ind][mid-orgl]>=k)
            {
                ans = mid;
                r=mid-1;
            }
            else l = mid+1;
        }
        return orgr-ans;
    }
    else if(l>e || r<s) return 0;
    else 
    {
        int mid = l + (r-l)/2;
        return query(segTree,l,mid,s,e,2*ind+1,k) + query(segTree,mid+1,r,s,e,2*ind+2,k);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<ll>> segTree(4*n);
    buildTree(arr,segTree,0,n-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int i,j,k;
        cin>>i>>j>>k;
        cout<<query(segTree,0,n-1,i,j,0,k)<<"\n";
    }
    return 0;
}