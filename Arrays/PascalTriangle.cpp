// Print N rows of pascal's Triangle

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        // Time-Complexity is O(n^2)

        vector<vector<int>> v(numRows); // User-defined row size in vector of vectors

        for (int i = 0; i < numRows; i++)
        {

            v[i].resize(i + 1);    // keeps increasing the size of each row as traingle goes down
            v[i][0] = v[i][i] = 1; // initialise first and last element 1

            for (int j = 1; j < i; j++) // iterate each row and put the sum according to given condition
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }

        return v;
    }
};