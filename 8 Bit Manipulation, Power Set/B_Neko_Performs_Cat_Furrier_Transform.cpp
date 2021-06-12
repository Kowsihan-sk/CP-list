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
#define Size(n) ((int)(n).size())
typedef vector<ll> vl;
#define pb push_back

bool isPow_of2(ll n)
{
    return (n && (!(n & (n - 1))));
}

int main()
{
    fast;
    ll n;
    cin >> n;

    ll i = 0;
    vl n_value;
    while (!isPow_of2(n + 1))
    {
        i++;
        if (i % 2)
        {
            ll pos = 0;
            for (int temp = n, count = 0; temp > 0; temp >>= 1, count++)
            {
                if ((temp & 1) == 0)
                    pos = count;
            }
            n_value.pb(pos + 1);
            // cout << pos << " " << (1 << pos + 1) << endl;
            n ^= ((1 << (pos + 1)) - 1);
        }
        else
            n += 1;
    }
    cout << i << endl;
    f(0, Size(n_value), 1) cout << n_value[i] << " ";

    return 0;
}