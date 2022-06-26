#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MAR(vector<int> &heights)
{ // COPIED FROM HISTOGRAM QUESTION

    // TIME-COMPLEXITY = O(N)
    // SPACE-COMPLEXITY = O(4N) ---> can be reduced to O(3N) by using either one of right or left vector to store the area

    stack<pair<int, int>> NSL;
    stack<pair<int, int>> NSR;
    vector<int> left;
    vector<int> right;

    vector<int> area;

    int n = heights.size() - 1;

    // i will traverse both from start and end. start pointer will add to NSL and right pointer will add to NSR

    for (int i = 0; i < heights.size(); i++)
    { // TC = O(N)

        if (NSL.empty())
        { // this if-else will get smaller to left
            NSL.push({heights[i], i});
            left.push_back(-1);
        }

        else
        {
            while (!NSL.empty() && NSL.top().first >= heights[i])
            {
                NSL.pop();
            }
            if (NSL.empty())
            {
                NSL.push({heights[i], i});
                left.push_back(-1);
            }
            else
            {
                left.push_back(NSL.top().second);
                NSL.push({heights[i], i});
            }
        }

        if (NSR.empty())
        { // this if-else will get smaller to right
            NSR.push({heights[n - i], n - i});
            right.push_back(n + 1);
        }

        else
        {
            while (!NSR.empty() && NSR.top().first >= heights[n - i])
            {
                NSR.pop();
            }
            if (NSR.empty())
            {
                NSR.push({heights[n - i], n - i});
                right.push_back(n + 1);
            }
            else
            {
                right.push_back(NSR.top().second);
                NSR.push({heights[n - i], n - i});
            }
        }
    }
    // we need to reverse right vecotr since we traversed from back
    reverse(right.begin(), right.end()); // TC = O(N)

    // now we compute area
    for (int i = 0; i < heights.size(); i++)
    { // TC = O(N)
        area.push_back(heights[i] * (right[i] - left[i] - 1));
    }

    return *max_element(area.begin(), area.end()); // TC = O(N)
}

int maximalRectangle(vector<vector<int>> &matrix)
{
    vector<int> tempHist(matrix[0].size());
    vector<int> maxAreaVec;

    for (int i = 0; i < matrix[0].size(); i++)
    {
        tempHist[i] = (int)matrix[0][i];
    }

    maxAreaVec.push_back(MAR(tempHist)); // computing for first row

    if (matrix.size() == 1)
    {
        int ans = maxAreaVec[0];
        return ans;
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; i < matrix[0].size(); j++)
        {
            cout << "code runs";
            if (matrix[i][j] == 0)
                tempHist[i] = 0; // deals with floating building
            else
                tempHist[i] += matrix[i][j];
        }

        maxAreaVec.push_back(MAR(tempHist));
    }

    return *max_element(maxAreaVec.begin(), maxAreaVec.end());
}

int main()
{
    vector<vector<int>> matrix{
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};
    cout << maximalRectangle(matrix);

    // vector<vector<char>> mat{'1','0','1'};

    return 0;
}
