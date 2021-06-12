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

void solve(vl ar, ll n)
{
    ll res = ar[0];
    f(1, n, 1) res ^= ar[i];

    res ^= (res & (res - 1));
    ll x = 0, y = 0;
    f(0, n, 1)
    {
        if (res & ar[i])
            x ^= ar[i];
        else
            y ^= ar[i];
    }
    cout << min(x, y) << " " << max(x, y) << endl;
}

int main()
{
    fast;
    ll n;
    cin >> n;
    vl ar(n);
    f(0, n, 1) cin >> ar[i];
    solve(ar, n);

    return 0;
}