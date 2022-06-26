// Return true if number comes out to be happy i.e. sum of squares of digits at some point is = 1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int b = n, sum = 0;
        if (n == 1 || n == 7)
            return true;
        else if (b / 10 == 0)
            return false;
        else
        {
            while (b != 0)
            {
                sum += (b % 10) * (b % 10);
                b = b / 10;
            }
        }

        bool k = isHappy(sum);
        if (k == true)
            return true;
        else
            return false;
    }
};