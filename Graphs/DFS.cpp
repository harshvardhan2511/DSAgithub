#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void mindegree(int edges[][2], int len, int n)
{

    // Map to store the degrees of every node
    map<int, int> m;

    for (int i = 0; i < len; i++)
    {

        // Storing the degree for each node
        m[edges[i][0]]++;
        m[edges[i][1]]++;
    }

    // minimum degree we need is 1

    int mini = 1;

    cout << "Special Edge exists b/w : ";
    for (int i = 1; i <= n; i++)
    {
        if (m[i] == mini)
        {
            for (int j = 0; j < n; j++)
            {
                if (edges[j][0] == i)
                    ans.push_back(make_pair(i, edges[j][1]));
            }
        }
    }
}

// Driver code
int main()
{

    // Count of nodes
    int n = 4;

    // The edge list
    int edges[][2] = {{1, 2},
                      {2, 3},
                      {2, 4},
                      {4, 3}};

    mindegree(edges, m, 4);

    cout << ans[0].first << " " << ans[0].second;
    return 0;
}