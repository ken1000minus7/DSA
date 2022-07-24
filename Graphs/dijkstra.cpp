#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

int main()
{
    FIO
    int n,e;
    cin>>n>>e;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    for(int _=0;_<e;_++)
    {
        int i,j,w;
        cin>>i>>j>>w;
        adj[i].push_back({j,w});
        adj[j].push_back({i,w});
    }
    pq.push({0,0});
    vector<int> dist(n,INT32_MAX);
    dist[0] = 0;
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int i = p.second;
        int d = p.first;
        for(auto pp : adj[i])
        {
            int j = pp.first;
            int w = pp.second;
            if(d+w<dist[j])
            {
                dist[j] = d+w;
                pq.push({dist[j],j});
            }
        }
    }
    for(int i : dist) cout<<i<<" ";
    cout<<"\n";
    return 0;
}