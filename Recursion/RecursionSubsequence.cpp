// Input an array and output will be all the possible subsequences made from that array.
// For example: for array (vector): 3---1--2
// The output subsequence should be: (3-1-2)(3,1)(3,2)(3)--(1,2)(1)(2)()
// Time Complexity: 2^n (pick or dont pick, 2 choices for every element in array.)
// Space Complexity: Depth of recursion tree i.e. = n

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Subseq(int ind, vector<int> &seq, vector<int> v, int N)
{
    if (ind >= N)
    {
        for (auto it : seq)
        {
            cout << it << " ";
        }
        if (seq.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }
    // do pick or take condition while adding elements to the subsequence
    seq.push_back(v[ind]); // seq={3}--{3,1}--{3,1,2} after printing 3,1,2 popping starts
    Subseq(ind + 1, seq, v, N);

    // not pick or take condition while adding elements to the subsequence
    seq.pop_back(); // seq={3,1}--{3}-{3,2}
    Subseq(ind + 1, seq, v, N);
}

int main()
{
    cout << "Enter how many elements: ";
    vector<int> v;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a); // 0, 1, 2
    }                   // eg v={3, 1, 2}
    vector<int> Seq;
    Subseq(0, Seq, v, n);
    return 0;
}