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
#define ff first
#define ss second
#define mp make_pair
typedef pair<ll, ll> pll;

vll lca, maxi, mini;
vector<vector<pll>> adj;
vl level;
ll maxN;

void dfs(ll node, ll lvl, ll par, ll dist)
{
    level[node] = lvl;
    lca[node][0] = par;
    if (dist != -1)
        maxi[node][0] = mini[node][0] = dist;

    for (pll child : adj[node])
    {
        if (child.ff != par)
            dfs(child.ff, lvl + 1, node, child.ss);
    }
}

void init(ll n)
{
    dfs(1, 0, -1, -1);

    f(1, maxN + 1, 1)
    {
        fo(j, 1, n + 1, 1)
        {
            if (lca[j][i - 1] != -1)
            {
                ll par = lca[j][i - 1];
                lca[j][i] = lca[par][i - 1];
                maxi[j][i] = max(maxi[j][i - 1], maxi[par][i - 1]);
                mini[j][i] = min(mini[j][i - 1], mini[par][i - 1]);
            }
        }
    }
}

ll getLCA(ll a, ll b)
{
    if (level[b] < level[a])
        swap(a, b);

    ll d = level[b] - level[a];
    while (d > 0)
    {
        ll i = log2(d);
        b = lca[b][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    fd(maxN, 0, 1)
    {
        if (lca[a][i] != -1 && lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    }
    return lca[a][0];
}

pll calc(ll a, ll b)
{
    pll p;
    p.ff = INT_MAX, p.ss = INT_MIN;

    if (level[b] < level[a])
        swap(a, b);
    ll d = level[b] - level[a];
    while (d > 0)
    {
        ll i = log2(d);
        p.ff = min(p.ff, mini[b][i]);
        p.ss = max(p.ss, maxi[b][i]);
        b = lca[b][i];
        d -= 1 << i;
    }

    return p;
}

int main()
{
    fast;

    ll n, a, b, q, x;

    cin >> n;
    adj.resize(n + 1), level.resize(n + 1);
    maxN = ceil(log2(n));
    lca.resize(n + 1, vl(maxN + 1, -1));
    maxi.resize(n + 1, vl(maxN + 1, INT_MIN)), mini.resize(n + 1, vl(maxN + 1, INT_MAX));

    f(1, n, 1)
    {
        cin >> a >> b >> x;
        adj[a].pb(mp(b, x)), adj[b].pb(mp(a, x));
    }

    init(n);

    ll lc;
    pll p;
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        lc = getLCA(a, b);
        if (lc == b || lc == a)
            p = calc(b, a);
        else
        {
            pll qq = calc(lc, a), pp = calc(lc, b);
            p.ff = min(qq.ff, pp.ff);
            p.ss = max(qq.ss, pp.ss);
        }
        cout << p.ff << " " << p.ss << endl;
    }
    return 0;
}