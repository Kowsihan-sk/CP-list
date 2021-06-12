/* Author : S Kowsihan */
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
typedef vector<vl> vll;

int main()
{
    fast;

    ll n, x;
    cin >> n >> x;

    vl ar(n);
    f(0, n, 1) cin >> ar[i];

    vector<vector<vector<ll>>> dp;
    dp.resize(n + 1, vll(2, vl(2)));

    dp[0][1][0] = ar[0];
    dp[0][1][1] = x * ar[0];

    ll ans = max({0LL, ar[0], x * ar[0]});
    f(1, n, 1)
    {
        dp[i][1][0] = max(ar[i], ar[i] + dp[i - 1][1][0]);
        dp[i][1][1] = max(x * ar[i], x * ar[i] + max(dp[i - 1][1][1], dp[i - 1][1][0]));
        dp[i][0][0] = max(ar[i], ar[i] + max(dp[i - 1][1][1], dp[i - 1][0][0]));
        ans = max({ans, dp[i][0][0], dp[i][1][0], dp[i][1][1]});
    }
    cout << ans << endl;

    return 0;
}