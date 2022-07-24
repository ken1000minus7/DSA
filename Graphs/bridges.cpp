#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout << "YES\n";
#define NO cout << "NO\n";
using namespace std;

void dfs(int i, int time, int parent, vector<vector<int>> &adj, vector<int> &reachTime, vector<int> &lowestNode, vector<int> &visited, vector<pair<int, int>> &bridges)
{
    if (visited[i])
        return;
    visited[i]++;
    reachTime[i] = lowestNode[i] = time++;
    for (int j : adj[i])
    {
        if (j == parent)
            continue;
        dfs(j, time, i, adj, reachTime, lowestNode, visited, bridges);
        if (lowestNode[j] > reachTime[i])
        {
            bridges.push_back({i, j});
        }
        else
        {
            lowestNode[i] = lowestNode[j];
        }
    }
}

int main()
{
    FIO int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n, vector<int>());
    for (int _ = 0; _ < e; _++)
    {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    vector<int> visited(n);
    vector<int> reachTime(n);
    vector<int> lowestNode(n);
    vector<pair<int, int>> bridges;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        dfs(i, 0, -1, adj, reachTime, lowestNode, visited, bridges);
    }
    for (auto p : bridges)
    {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}