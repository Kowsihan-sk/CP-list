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
typedef vector<vl> vll;

vll adj;
vl vis, low, tin;
ll timer;
set<ll> cut_points;

void dfs(ll node, ll par = -1)
{
    vis[node] = 1;
    low[node] = tin[node] = timer++;
    ll children = 0;

    for (ll child : adj[node])
    {
        if (child == par)
            continue;

        if (vis[child])
        {
            low[node] = min(low[node], tin[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= tin[node] && par != -1)
            {
                // cutoff vertice
                cut_points.insert(node);
            }
            children++;
        }
    }
    if (par == -1 && children > 1)
    {
        // cutoff vertice
        cut_points.insert(node);
    }
}

void cutpoints(ll n)
{
    vis.resize(n + 1, 0), low.resize(n + 1, -1), tin.resize(n + 1, -1);
    timer = 1;

    f(1, n + 1, 1)
    {
        if (!vis[i])
            dfs(i);
    }

    vis.clear(), low.clear(), tin.clear();
}

int main()
{
    fast;

    ll n, m;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        adj.resize(n + 1);

        ll a, b;
        f(0, m, 1) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

        cutpoints(n);
        cout << cut_points.size() << endl;

        adj.clear(), cut_points.clear();
    }
    return 0;
}