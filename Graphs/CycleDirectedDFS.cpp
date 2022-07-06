// Checking if cycle exists in Directed Graph

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adj[], int vis[], int dfsvis[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, adj, vis, dfsvis))
                return true;
        }
        else if (dfsvis[it])
        {
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}

bool isCyclic(int N, vector<int> adj[])
{
    int vis[N], dfsvis[N];
    memset(vis, 0, sizeof vis);
    memset(dfsvis, 0, sizeof dfsvis);

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, dfsvis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        cout << "iteration " << i << endl;
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);    //not using this since this time we use directed graph
    }

    if (isCyclic(n, adj))

        cout << "YES cycle exists";
    else
        cout << "NO cycle does not exist";
    return 0;
}
