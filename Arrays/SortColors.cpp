// Basically sort 0's 1's and 2's
// Dutch National Flag 3 - Pointer algo

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        // Time-Complexity = O(n)
        // Space-Complexity = O(1)

        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            switch (nums[mid])
            {

                // If element is found to be 0
            case 0:
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;

                // If element is found to be 1
            case 1:
                mid++;
                break;

                // If element if found to be 2
            case 2:
                swap(nums[mid], nums[high]);
                high--;
                break;
            }
        }
    }
};
