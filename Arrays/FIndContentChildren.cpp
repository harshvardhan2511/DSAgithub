#include <iostream>
#include <bits/stdc++.h> // 1  2  3
using namespace std;     // 1  1

int findContentChildren(vector<int> &g, vector<int> &s)
{

    int i = 0, j = 0, sumCookie = 0, contentNigga = 0;

    while (i < g.size() && j < s.size())
    {

        if (g[i] <= s[j])
        {
            contentNigga++;
            s[j + 1] += (s[j] - g[i]); // transfers leftover cookie to next index
            i++;
            j++;
        }

        else
        {
            while (g[i] > sumCookie && j < s.size())
            {
                sumCookie += s[j];
                j++;
                cout << "code runs";
            }
            if (g[i] < sumCookie)
                contentNigga++; // 3       1 1 2 1 1
            if (j < s.size())
                s[j] += (sumCookie - g[i]); // prevents heap overflow i.e. trying to access an s[j] that is out of bounds
            i++;
            sumCookie = 0;
        }
    }

    return contentNigga;
}

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << "\n"
         << findContentChildren(g, s);
    return 0;
}
