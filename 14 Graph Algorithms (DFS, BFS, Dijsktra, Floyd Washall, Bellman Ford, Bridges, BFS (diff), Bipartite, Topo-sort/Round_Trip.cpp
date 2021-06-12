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
typedef vector<vl> vll;

vll g;
vl vis, par;
ll sv, ev;

bool dfs(ll n, ll p)
{
    vis[n] = 1;
    par[n] = p;
    for (ll child : g[n])
    {
        if (child == p)
            continue;
        if (vis[child])
        {
            sv = child, ev = n;
            return true;
        }
        else if (dfs(child, n))
            return true;
    }
    return false;
}

bool visit_all(ll n)
{
    f(1, n + 1, 1)
    {
        if (!vis[i])
            if (dfs(i, -1))
                return true;
    }
    return false;
}

int main()
{
    fast;

    ll n, m, a, b;
    cin >> n >> m;
    g.resize(n + 1), vis.resize(n + 1, 0), par.resize(n + 1, -1);

    f(0, m, 1) cin >> a >> b, g[a].pb(b), g[b].pb(a);
    if (!visit_all(n))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vl ans;
    ll currv = ev;
    ans.pb(ev);
    while (currv != sv)
    {
        ans.pb(par[currv]);
        currv = par[currv];
    }
    ans.pb(ev);

    cout << sz(ans) << endl;
    for (ll i : ans)
        cout << i << " ";

    return 0;
}