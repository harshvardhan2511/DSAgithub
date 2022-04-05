// Rotate a N x N matrix by 90 degrees to right

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        // Time-Complexity: O(N^2) + O(N^2)
        // Space-Complexity: O(1)

        int i;
        for (i = 0; i < matrix.size(); i++) // Find transpose of matrix
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (i = 0; i < matrix.size(); i++) // Reverse each row of transposed matrix
            reverse(matrix[i].begin(), matrix[i].end());
    }
};