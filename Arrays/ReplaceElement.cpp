#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

void arrayChange(vector<int> &nums, vector<vector<int>> &operations)
{

    int j = 0; // will iterate the rows of operations
    int i = 0; // will iterate the nums array

    unordered_map<int, int> umap;
    while (j != operations.size())
    {
        cout << "running";
        auto pos = umap.find(operations[j][0]);
        if (nums[i] == operations[j][0])
        {
            nums[i] = operations[j][1];
            umap[nums[i]] = i; // maos as "value -> index"
            i++;
            j++;
            continue;
        }

        else if (pos != umap.end())
        {
            nums[pos->second] = operations[j][1];
            i++;
            j++;
            continue;
        }

        else
        {
            umap[nums[i]] = i;
            i++;
            continue;
        }
        j++;
    }

    // for (auto it = umap.begin(); it != umap.end(); ++it)
    //     cout << it->first << "\t" << it->second;
    // cout << endl;
}

int main()
{
    vector<int> nums = {1, 2};
    vector<vector<int>> operations = {{1, 3},
                                      {2, 1},
                                      {3, 2}};
    arrayChange(nums, operations);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "\t";
    }
    return 0;
}
