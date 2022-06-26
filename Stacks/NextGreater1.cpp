#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time-Complexity = O(m+n) m is length of bigger vector
// Space-Complexity = O(m)

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    unordered_map<int, int> umap;
    vector<int> ans;
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {

        if (s.size() == 0)
        {
            s.push(nums2[i]);
            umap[nums2[i]] = -1;
        }

        else if (s.top() > nums2[i])
        {
            umap[nums2[i]] = s.top();
            s.push(nums2[i]);
        }

        else if (s.top() < nums2[i])
        {

            while (s.size() != 0 && s.top() < nums2[i])
            {

                s.pop();
            }

            if (s.size() == 0)
            {
                umap[nums2[i]] = -1;
                s.push(nums2[i]);
            }
            else
            {
                umap[nums2[i]] = s.top();
                s.push(nums2[i]);
            }
        }
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        auto temp = umap.find(nums1[i]);
        ans.push_back(temp->second);
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> answer = nextGreaterElement(nums1, nums2);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\t";
    }
    return 0;
}
