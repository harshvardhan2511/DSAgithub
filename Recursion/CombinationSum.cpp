#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void CombSum(int ind, int target, vector<int> &ds, vector<int> v, int N)
{
    if (ind == v.size())
        if (target == 0)
        {
            for (auto it : ds)
            {
                cout << it << "\t";
            }
            cout << endl;
            return;
        }

    // Picking the element
    if (v[ind] <= target)
    {
        ds.push_back(v[ind]);
        CombSum(ind, target - v[ind], ds, v, N);
        ds.pop_back();
    }

    // Not picking the element
    CombSum(ind + 1, target, ds, v, N);
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
