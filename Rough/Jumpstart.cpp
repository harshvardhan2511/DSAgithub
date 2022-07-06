#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countSeq(string sign, int current, vector<int> ar, int count, int n, int iteration, vector<int> smaller, vector<int> greater)
{
    cout << "runs" << endl;
    if (iteration = n)
        return count++;

    if (sign[iteration] == '+')
    { // we want greater element next
        if (greater.size() != 0)
        {
            int removed = greater[0];
            auto it = greater.begin();
            greater.erase(it);
            count = countSeq(sign, greater[0], ar, count, n, iteration++, smaller, greater);
            greater.insert(greater.begin(), removed);
        }

        else
            return count;
    }
    else
    { // we want smaller element
        if (smaller.size() != 0)
        {
            int removed = smaller[0];
            auto it = smaller.begin();
            smaller.erase(it);
            count = countSeq(sign, smaller[0], ar, count, n, iteration++, smaller, greater);
            smaller.insert(smaller.begin(), removed);
        }

        else
            return count;
    }
    return count;
}

int main()
{
    string s = "+--";
    int n = s.size();
    vector<int> ar; // 0 1 2

    for (int i = 0; i < n; i++)
    {
        ar.push_back(i);
    }

    /*
    using two vectors. one to store elements greater than current
    and other to store elements smaller than current and passing them
    to function on every recursive call
    */
    vector<int> greater;
    vector<int> smaller;
    for (int i = 0; i < n; i++)
    {

        // storing greater element
        int j = ar[j] + 1;
        while (j < n)
        {
            greater.push_back(j);
            j++;
        }
        // storing smaller element
        j = ar[j] - 1;
        while (j > -1)
        {
            smaller.push_back(j);
            j--;
        }
        cout << countSeq(s, ar[i], ar, 0, n, 0, smaller, greater) << endl;
    }

    return 0;
}
