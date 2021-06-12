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
const int mod = 1e9 + 7;

int main()
{
    fast;

    ll n, m;
    cin >> n >> m;

    vl ar(n), dp(m + 1);
    f(0, n, 1) cin >> ar[i];
    dp[0] = 1;

    f(1, m + 1, 1)
    {
        for (ll x : ar)
        {
            if (i - x >= 0)
                dp[i] += dp[i - x] % mod;
        }
    }
    cout << dp[m] % mod;

    return 0;
}