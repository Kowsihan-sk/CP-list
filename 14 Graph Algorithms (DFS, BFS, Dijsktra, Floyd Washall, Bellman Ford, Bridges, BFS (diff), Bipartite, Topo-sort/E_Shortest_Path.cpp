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
#define sz(n) ((int)(n).size())
typedef vector<ll> vl;
#define pb push_back
#define all(n) (n).begin(), (n).end()
typedef vector<vl> vll;
#define ff first
#define ss second
typedef pair<ll, ll> pll;

vll par, adj;
map<pair<pll, ll>, ll> bList;
queue<pll> q;
pll ans = {-1, -1};
ll n, m;

void dfs()
{
    q.push({1, 1});
    while (!q.empty())
    {
        ll u = q.front().ff, v = q.front().ss;
        q.pop();
        if (v == n)
        {
            ans = {u, v};
            return;
        }
        for (ll i : adj[v])
        {
            if (par[v][i] || bList[{{u, v}, i}])
                continue;
            par[v][i] = u;
            q.push({v, i});
        }
    }
}

int main()
{
    fast;

    ll q, a, b, c;
    cin >> n >> m >> q;
    adj.resize(n + 1), par.resize(n + 1, vl(n + 1));
    f(0, m, 1) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

    f(0, q, 1)
    {
        cin >> a >> b >> c;
        bList[{{a, b}, c}] = 1;
    }

    dfs();

    if (ans.ff == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    vl path;
    while (ans.ss != 1)
    {
        path.pb(ans.ss);
        ans = {par[ans.ff][ans.ss], ans.ff};
    }
    path.pb(1);
    reverse(all(path));

    cout << sz(path) - 1 << endl;
    for (ll i : path)
        cout << i << " ";

    return 0;
}
