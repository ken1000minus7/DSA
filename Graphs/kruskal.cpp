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
    int n,e;
    cin>>n>>e;
    vector<int> parent(n,-1);
    vector<int> rank(n);
    vector<vector<int>> edges;
    for(int _=0;_<e;_++)
    {
        int i,j,w;
        cin>>i>>j>>w;
        edges.push_back({i,j,w});
    }
    sort(edges.begin(),edges.end(),[&](vector<int> &v1, vector<int> &v2){
        return v1[2]<v2[2];
    });
    vector<vector<int>> mst;
    for(auto v : edges)
    {
        int i = v[0];
        int j = v[1];
        int w = v[2];
        if(find(i,parent)!=find(j,parent))
        {
            mst.push_back(v);
            unifyboi(i,j,parent,rank);
        }
    }
    int weight = 0;
    for(auto v : mst)
    {
        cout<<v[0]<<" "<<v[1]<<"\n";
        weight+=v[2];
    }
    cout<<weight<<"\n";
    return 0;
}