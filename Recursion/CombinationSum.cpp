// Generate the combinations in order to get the desired sum.
// Time Complexity = (2^k)*main
// Space Complexity = Depth of the recursion tree = n

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void CombSum(int ind, int target, vector<int> &ds, vector<int> v, int N)
{
    if (ind == v.size()) // When flow of control reaches the end of vector
        if (target == 0) // Checks whether the combination was correct
        {
            for (auto it : ds)
            {
                cout << it << "\t";
            }
            cout << endl;
            return;
        }

    // Picking the element
    if (v[ind] <= target) // Pick element only if number is less than target
    {
        ds.push_back(v[ind]);                    // push the number in another data structre. Here i used vector.
        CombSum(ind, target - v[ind], ds, v, N); // Subtract the number from target and call function again
        ds.pop_back();                           // While returning pop back the last eleemnt. Since pushing was done before calling the function, mandatory to remove the undesired element which made it return.
    }

    // Not picking the element
    CombSum(ind + 1, target, ds, v, N); // Basically not pick and moving onto the next element.
}

int main()
{
    int a, n, tar;
    cout << "Enter how many elements you want to enter: ";
    cin >> n;
    cout << "\nEnter the target: ";
    cin >> tar;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    vector<int> ds;
    CombSum(0, tar, ds, v, n);
    return 0;
}
