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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<vl> vll;
const int mod = 1e9 + 7;

ll n, m;
vector<string> grid;
vll dp;

int main()
{
    fast;

    cin >> n >> m;
    grid.resize(n);
    dp.resize(n, vl(m));
    dp[0][0] = 1;

    f(0, n, 1) cin >> grid[i];
    f(0, n, 1)
    {
        fo(j, 0, m, 1)
        {
            if (grid[i][j] == '#')
                continue;
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
                dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j] % mod) + (dp[i][j - 1] % mod)) % mod;
        }
    }
    cout << dp[n - 1][m - 1] << endl;

    return 0;
}