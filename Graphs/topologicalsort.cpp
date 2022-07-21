#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

// O(V + E)
void dfs(int i,vector<vector<int>> &adj,vector<int> &visited,stack<int> &s)
{
    if(visited[i]) return;
    visited[i]++;
    for(int j : adj[i])
    {
        dfs(j,adj,visited,s);
    }
    s.push(i);
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> visited(n);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        dfs(i,adj,visited,s);
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
    return 0;
}