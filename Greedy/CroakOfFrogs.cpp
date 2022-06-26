#include <iostream>
using namespace std;
int main()
{
    string croakOfFrogs = "croakcroak";
    int c = 0, r = 0, o = 0, a = 0, k = 0;
    int ans = 0, activeFrog = 0;

    for (int i = 0; i < croakOfFrogs.length(); i++)
    {
        switch (croakOfFrogs[i])
        {
        case 'c':
            c++;
            activeFrog++;
            break;
        case 'r':
            r++;
            break;
        case 'o':
            o++;
            break;
        case 'a':
            a++;
            break;
        case 'k':
            k++;
            activeFrog--;
            break;
        }

        ans = max(ans, activeFrog);
        if (c < r || r < o || o < a || a < k)
        {
            cout << c << r << o << a << k << "\t";
            cout << "-1";
        }
    }
    cout << ans;
}
