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
#define pb push_back
#define ff first
#define ss second
typedef pair<ll, ll> pll;

vector<vector<pll>> adj;
vl vis, dist, par;
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijkstra()
{
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        ll curr = pq.top().ss, curr_d = pq.top().ff;
        pq.pop();

        if (vis[curr])
            continue;
        vis[curr] = 1;

        for (pll edge : adj[curr])
        {
            if (curr_d + edge.ss < dist[edge.ff])
            {
                dist[edge.ff] = curr_d + edge.ss;
                par[edge.ff] = curr;
                pq.push({dist[edge.ff], edge.ff});
            }
        }
    }
}

void spath(ll n)
{
    if (n != 1)
        spath(par[n]);
    cout << n << " ";
}

int main()
{
    fast;
    ll n, m, a, b, w;
    cin >> n >> m;

    adj.resize(n + 1), vis.resize(n + 1, 0), par.resize(n + 1, 0), dist.resize(n + 1, 1e18);
    f(0, m, 1) cin >> a >> b >> w, adj[a].pb({b, w}), adj[b].pb({a, w});

    dijkstra();
    if (dist[n] == 1e18)
        cout << -1;
    else
        spath(n);
    return 0;
}