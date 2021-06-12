#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        int flag = 0;
        fo(i, 0, s.length())
        {
            if (s[i] == '1')
            {
                if (flag == 2)
                {
                    flag = 0;
                    break;
                }
                flag = 1;
            }
            else if (flag == 1)
            {
                flag = 2;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}