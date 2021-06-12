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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<ll> vl;
typedef vector<vl> vll;
const int mod = 1e9 + 7;

int main()
{
    fast;

    ll n, m;
    cin >> n >> m;

    // vl ar(n);
    vector<int> ar(n);
    f(0, n, 1) cin >> ar[i];
    // vll dp(n + 1, vl(m + 1));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    f(1, n + 1, 1)
    {
        fo(j, 0, m + 1, 1)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
            {
                ll op1 = (i == 1) ? 0 : dp[i - 1][j];
                ll op2 = (ar[i - 1] > j) ? 0 : dp[i][j - ar[i - 1]];
                dp[i][j] = (op1 + op2) % mod;
            }
        }
    }

    cout << dp[n][m] % mod;

    return 0;
}