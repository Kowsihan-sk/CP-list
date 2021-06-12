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

vll adj;
vl vis, par;

void bfs(ll n)
{
    vis[n] = 1;
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = 1, par[v] = u;
                q.push(v);
            }
        }
    }
}

int main()
{
    fast;

    ll n, m, a, b;
    cin >> n >> m;

    adj.resize(n + 1), vis.resize(n + 1, 0), par.resize(n + 1, -1);
    f(0, m, 1) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

    bfs(1);
    if (!vis[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    ll curr = n;
    vl path;
    while (curr != -1)
    {
        path.pb(curr);
        curr = par[curr];
    }
    reverse(all(path));

    cout << sz(path) << endl;
    f(0, sz(path), 1) cout << path[i] << " ";

    return 0;
}