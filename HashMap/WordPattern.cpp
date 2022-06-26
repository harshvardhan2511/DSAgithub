#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{

    unordered_map<char, string> umap;
    int i = 0, j = 0;
    string temp;
    char ch;

    while (i < pattern.size())
    {
        while (s[j] != ' ' && j < s.size())
        {
            ch = s[j];
            temp.push_back(ch);
            j++;
        }
        
        j += 1; // to move past empty space

        if (umap.find(pattern[i]) != umap.end())
        {
            if (umap[pattern[i]] != temp)
                return false;
        }
        else
        {
            umap[pattern[i]] = temp;
        }

        cout << umap[pattern[i]] << endl;
        temp.clear();
        i++;
    }
    
    return true;
}

int main()
{
    if (wordPattern("abba", "dog cat cat dog") == false)
        cout << "false";
    return 0;
}
