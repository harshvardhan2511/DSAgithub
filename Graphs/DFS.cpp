#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;



// Driver code
int main()
{

    // Count of nodes
    int n = 4, m = 4;

    // The edge list
    int edges[][2] = {{1, 2},
                      {2, 3},
                      {2, 4},
                      {4, 3}};

   
    cout << ans[0].first << " " << ans[0].second;
    return 0;
}