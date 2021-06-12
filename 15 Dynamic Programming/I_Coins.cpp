/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define db double
#define endl "\n"
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)

int main()
{
    fast;

    cout << fixed << setprecision(10);
    ll n;
    cin >> n;

    vector<db> v(n);
    f(0, n, 1) cin >> v[i];
    vector<vector<db>> dp(n + 1, vector<db>(n + 1, 0.0));
    dp[0][0] = 1;

    f(1, n + 1, 1)
    {
        fo(j, 0, i + 1, 1)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] * (1 - v[i - 1]);
            else
                dp[i][j] = dp[i - 1][j] * (1 - v[i - 1]) + dp[i - 1][j - 1] * v[i - 1];
        }
    }
    db ans = 0.0;
    fd(n, n / 2 + 1, 1) ans += dp[n][i];
    cout << ans;

    return 0;
}