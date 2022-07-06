#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<pair<int, int>> ans;

bool checkForCycle(int node, int V, vector<int> &visited, vector<int> adj[])
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            checkForCycle(it, node, visited, adj);
        }
    }
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, -1, vis, adj))
                return true;
        }
    }

    return false;
}
// Driver code (Not supposed to be used. Only above code hold right)
int main()
{

    // Count of nodes
    int n = 9;

    int edges[][2] = {{1, 2},
                      {2, 3},
                      {2, 4},
                      {4, 3}};

    cout << ans[0].first << " " << ans[0].second;
    return 0;
}