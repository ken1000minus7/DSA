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
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int _=0;_<e;_++)
    {
        int i,j,w;
        cin>>i>>j>>w;
        adj[i].push_back({j,w});
        adj[j].push_back({i,w});
    }
    vector<int> key(n,INT32_MAX);
    vector<int> parent(n,-1);
    vector<int> done(n);
    key[0] = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int i = p.second;
        done[i]++;
        for(auto pp : adj[i])
        {
            int j = pp.first;
            int w = pp.second;
            if(done[j]) continue;
            if(w<key[j])
            {
                key[j] = w;
                parent[j] = i;
                pq.push({w,j});
            }
        }
    }
    int weight = 0;
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" "<<i<<"\n";
        weight += key[i];
    }
    cout<<weight<<"\n";
    return 0;
}