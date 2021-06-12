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

vll dp;
ll n, W;
vl wt, val;

ll knapsackRecursive1(vl wt, vl val, ll w, ll n)
{
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
        return dp[n][w] = max(val[n - 1] + knapsackRecursive1(wt, val, w - wt[n - 1], n - 1), knapsackRecursive1(wt, val, w, n - 1));
    else
        return dp[n][w] = knapsackRecursive1(wt, val, w, n - 1);
}

ll knapsackRecursive2(ll id, ll w)
{
    // more efficient
    if (id == n)
        return 0;

    if (dp[id][w] != -1)
        return dp[id][w];

    ll ans = knapsackRecursive2(id + 1, w);

    if (wt[id] + w <= W)
        ans = max(ans, val[id] + knapsackRecursive2(id + 1, w + wt[id]));

    return dp[id][w] = ans;
}

ll knapsack(vl wt, vl val, ll w, ll n)
{
    f(1, n + 1, 1)
    {
        fo(j, 1, w + 1, 1)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][w];
}

int main()
{
    fast;
    cin >> n >> W;

    wt.resize(n), val.resize(n);
    dp.resize(n + 1, vl(W + 1, -1)); // for recursive
    // dp.resize(n + 1, vl(W + 1)); // for top down
    f(0, n, 1) cin >> wt[i] >> val[i];
    // cout << knapsack(wt, val, W, n);
    // cout<<knapsackRecursive1(wt, val, W, n);
    cout << knapsackRecursive2(0, 0);

    return 0;
}