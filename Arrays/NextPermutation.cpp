// Find out the next permutation according to the dictionary order/
// Time Complexity: O(n) + O(n) + O(n) = O(n)
// Space Complexity: O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int l, f;
        for (f = nums.size() - 2; f >= 0; f--)
        {
            if (nums[f] < nums[f + 1])
                break;
        }

        if (f < 0)
            reverse(nums.begin(), nums.end());

        else
        {

            for (l = nums.size() - 1; l > f; l--)
            {
                if (nums[f] < nums[l])
                    break;
            }

            swap(nums[f], nums[l]);
            reverse(nums.begin() + f + 1, nums.end());
        }
    }
};