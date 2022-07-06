// Topological sort using DFS
/*
Linear ordering of vertices such that if there is an edge, u -> v, u apperas before
v in ordering.
There can be multiple topological sorts for a given graph.
Topological sort is only possible for DAG i.e. Directed Acyclic (no cycle) Graphs
*/

#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            findTopoSort(it, vis, st, adj);
    }
    st.push(node);
}

vector<int> topoSort(int N, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(N, 0);
    for (int i = 0; i < N; i++)
        if (vis[i] == 0)
            findTopoSort(i, vis, st, adj);

    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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

    vector<int> sorted = topoSort(n, adj);
    for (auto it : sorted)
    {
        cout << it << " ";
    }
    return 0;
}