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
typedef vector<vl> vll;
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)

vll dp;
ll n, W, val_max = 0;
vl wt, val;

// ll rec_solve_w(ll rem, ll idx)
// {
//     if (idx == n)
//         return rem == 0 ? 0 : INT_MAX;

//     if (dp[idx][rem] != -1)
//         return dp[idx][rem];
//     ll ans = rec_solve_w(rem, idx + 1);
//     if (val[idx] <= rem)
//         ans = min(ans, wt[idx] + rec_solve_w(rem - val[idx], idx + 1));

//     return dp[idx][rem] = ans;
// }

// ll rec_max_val(ll val_max)
// {
//     fd(val_max, 0, 1)
//     {
//         if (rec_solve_w(i, 0) <= W)
//             return i;
//     }
//     return 0;
// }

ll knapsack(ll val_max)
{
    dp[0][0] = 0;
    dp[0][val[0]] = wt[0];

    f(1, n, 1)
    {
        dp[i][0] = 0;
        fo(j, 1, val_max + 1, 1)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= val[i])
                dp[i][j] = min(dp[i][j], wt[i] + dp[i - 1][j - val[i]]);
        }
    }

    fd(val_max, 0, 1)
    {
        if (dp[n - 1][i] <= W)
            return i;
    }
    return 0;
}

int main()
{
    fast;
    cin >> n >> W;

    wt.resize(n), val.resize(n);

    f(0, n, 1) cin >> wt[i] >> val[i], val_max += val[i];
    // dp.resize(n + 1, vl(val_max + 1, -1));      // for recursive
    // cout << rec_max_val(val_max);
    dp.resize(n + 1, vl(val_max + 1, INT_MAX)); // for top down
    cout << knapsack(val_max);

    return 0;
}