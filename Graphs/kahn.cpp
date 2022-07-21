#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

// O(V + E)
int main()
{
    FIO
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        ans.push_back(i);
        for(int j : adj[i])
        {
            indegree[j]--;
            if(indegree[j]==0) q.push(j);
        }
    }
    for(int i : ans) cout<<i<<" ";
    cout<<"\n";
    return 0;
}