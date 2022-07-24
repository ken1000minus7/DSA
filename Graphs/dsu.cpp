#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

int find(int i,vector<int> &parent)
{
    if(parent[i]==-1) return i;
    return parent[i] = find(parent[i],parent);
}

void unifyboi(int i,int j,vector<int> &parent,vector<int> &rank)
{
    while(parent[i]!=-1) i=parent[i];
    while(parent[j]!=-1) j=parent[j];
    if(i==j) return;
    if(rank[i]<=rank[j])
    {
        parent[i]=j;
        if(rank[i]==rank[j]) rank[j]++;
    }
    else
    {
        parent[j]=i;
    }
}

int main()
{
    FIO
    int n;
    cin>>n;
    vector<int> parent(n,-1);
    vector<int> rank(n);
    return 0;
}