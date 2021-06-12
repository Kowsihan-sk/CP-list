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
#define pb push_back
#define all(n) (n).begin(), (n).end()
typedef vector<vl> vll;

ll n, m;
vll adj;
vl vis, dp;

void dfs(ll n)
{
    if (vis[n] == 1)
        return;
    vis[n] = 1;

    for (ll child : adj[n])
    {
        if (!vis[child])
            dfs(child);
        dp[n] = max(dp[n], dp[child] + 1);
    }
}

int main()
{
    fast;

    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1), dp.resize(n + 1);

    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    f(1, n + 1, 1)
    {
        if (!vis[i])
            dfs(i);
    }
    cout << *max_element(all(dp)) << endl;

    return 0;
}