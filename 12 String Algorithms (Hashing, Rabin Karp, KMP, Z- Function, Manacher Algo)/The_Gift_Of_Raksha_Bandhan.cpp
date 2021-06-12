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
#define sz(n) ((int)(n).size())
typedef vector<ll> vl;

vl ZAlgo(string s)
{
    ll l = 0, r = 0, n = sz(s);
    vl z(n);
    f(1, n, 1)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r] == s[r - l])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            // inside box
            ll k = i - l;
            // if value does not cross right bound then just copy
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else
            {
                // try to see more matches
                l = i;
                while (r < n && s[r] == s[r - l])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

int main()
{
    fast;

    ll TT, x;
    string s;
    cin >> s;
    vl z = ZAlgo(s);
    cin >> TT;
    while (TT--)
    {
        cin >> x;
        cout << min(z[x], x) << endl;
    }

    return 0;
}