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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)
typedef vector<vl> vll;

vll adj, lca;
vl level;
ll maxN;

void dfs(ll node, ll lvl, ll par)
{
    level[node] = lvl;
    lca[node][0] = par;

    for (ll child : adj[node])
    {
        if (child != par)
            dfs(child, lvl + 1, node);
    }
}

void init(ll n)
{
    dfs(1, 0, -1);

    f(1, maxN + 1, 1)
    {
        fo(j, 1, n + 1, 1)
        {
            if (lca[j][i - 1] != -1)
            {
                ll par = lca[j][i - 1];
                lca[j][i] = lca[par][i - 1];
            }
        }
    }
}

int main()
{
    fast;

    ll n, a, b, q, x;

    cin >> n >> q;
    adj.resize(n + 1), level.resize(n + 1);
    maxN = ceil(log2(n));
    lca.resize(n + 1, vl(maxN + 1, -1));

    f(2, n + 1, 1) cin >> x, adj[i].pb(x), adj[x].pb(i);

    init(n);

    while (q--)
    {
        cin >> a >> b;
        ll node = a;
        f(0, maxN + 1, 1)
        {
            if (b & (1 << i) && node != -1)
                node = lca[node][i];
        }
        cout << node << endl;
    }
    return 0;
}