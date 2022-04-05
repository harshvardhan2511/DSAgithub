// Find out the best time to buy and sell stock.
// In this code we will only print the maximum profit that can be obtained

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        // Time-Complexity = O(n)
        // Space-Complexity = O(1)

        int profit = 0, currentMin = INT_MAX;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < currentMin)
            { // Keep storing the minimum price encounterd. This is the time to buy stock.
                currentMin = prices[i];
            }
            if (profit < prices[i] - currentMin) // Keep storing the meximum profit that can be made.
                profit = prices[i] - currentMin;
        }

        return profit;
    }
};