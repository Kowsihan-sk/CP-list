/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
typedef vector<ll> vl;
#define pb push_back
#define all(n) (n).begin(), (n).end()
typedef vector<vl> vll;

vll adj;
vl dp, lev;
void dfs(ll node, ll par = -1, ll level = 0)
{
    lev[node] = level;
    ll cnt = 0;
    for (ll child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node, level + 1);
            cnt += dp[child];
        }
    }
    dp[node] = 1 + cnt;
}

int main()
{
    fast;

    ll n, k, a, b;
    cin >> n >> k;
    adj.resize(n + 1), dp.resize(n + 1), lev.resize(n + 1);
    f(1, n, 1) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

    dfs(1);
    vl dist;
    f(1, n + 1, 1) dist.pb(lev[i] - (dp[i] - 1));
    sort(all(dist));
    reverse(all(dist));
    ll ans = 0;
    f(0, k, 1) ans += dist[i];
    cout << ans;

    return 0;
}