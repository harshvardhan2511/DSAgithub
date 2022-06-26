// Find out the maximum sum of elements that can be possible in a continuous subarray.
// Space Complexity: O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //Time-Complexity = O(n)
       
        int currentMax = nums[0], sum = nums[0];
        
        for(int i = 1; i<nums.size(); i++){
           if(sum < 0) sum = 0;   //if sum comes out to be negative at any point, make it 0.
            sum += nums[i];
            if(sum > currentMax) currentMax = sum;  //store max out of two i.e. sum and currentMax
        }
        
        return currentMax;
        
    }
};