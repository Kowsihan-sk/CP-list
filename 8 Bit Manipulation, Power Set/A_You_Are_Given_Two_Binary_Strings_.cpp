/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define endl "\n"

int main()
{
    fast;
    ll TT;
    cin >> TT;

    string a, b;
    ll i, j;
    while (TT--)
    {
        cin >> a >> b;
        for (j = 0; b[b.size() - 1 - j] == '0'; j++)
            ;
        for (i = 0; a[a.size() - 1 - j - i] == '0'; i++)
            ;
        cout << i << endl;
    }


    return 0;
}
