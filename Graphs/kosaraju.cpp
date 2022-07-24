#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

// O(V + E)
void topoSort(int i,vector<vector<int>> &adj,vector<int> &visited,stack<int> &s)
{
    if(visited[i]) return;
    visited[i]++;
    for(int j : adj[i])
    {
        topoSort(j,adj,visited,s);
    }
    s.push(i);
}

void dfs(int i,vector<vector<int>> &adj,vector<int> &visited)
{
    if(visited[i]) return;
    visited[i]++;
    cout<<i<<" ";
    for(int j : adj[i])
    {
        dfs(j,adj,visited);
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    vector<vector<int>> transpose(n);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        transpose[b].push_back(a);
    }
    vector<int> visited(n);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        topoSort(i,adj,visited,s);
    }
    vector<int> done(n);
    while (!s.empty())
    {
        int i = s.top();
        s.pop();
        if(done[i]) continue;
        dfs(i,transpose,done);
        cout<<"\n";
    }
    return 0;
}