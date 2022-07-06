#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<pair<int, int>> ans;

bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
{
    queue<pair<int, int>> q;

    visited[s] = true;
    q.push({s, -1});

    while (!q.empty())
    {

        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it, node});
            }
            else if (par != it)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, V, adj, vis))
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