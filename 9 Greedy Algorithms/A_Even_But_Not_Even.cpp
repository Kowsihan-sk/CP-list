/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define endl "\n"
#define f(a, b, c) for (ll i = a; i < b; i += c)
typedef vector<ll> vl;
#define pb push_back

int main()
{
    fast;
    ll TT;
    cin >> TT;

    while (TT--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll count = 0;
        vl arr;
        f(0, n, 1)
        {
            if (count < 2 && (((int)s[i]) - 48) % 2)
                arr.pb(((int)s[i]) - 48), count++;
            if (count >= 2)
                break;
        }
        if (count < 2)
            cout << "-1\n";
        else
            cout << arr[0] << arr[1] << endl;
    }

    return 0;
}