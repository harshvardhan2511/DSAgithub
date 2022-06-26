#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minMaxGame(vector<int> &nums)
{

    int n;
    vector<int> newNums(n / 2);
    while (n != 1)
    {
        n = (int)nums.size();
        if (n == 2)
            return nums[0];
        for (int i = 0; i < n / 2; i++)
        {
            if (i % 2 == 0)
                newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
            else
                newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
        }
        nums.clear();
        nums = newNums;
        n = n / 2;
    }

    return nums[0];
}

int main()
{
    vector<int> nums = {1, 3, 5, 2, 4, 8, 2, 2};
    cout << minMaxGame(nums);
    return 0;
}
