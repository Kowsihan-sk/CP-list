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
#define ff first
#define ss second
typedef pair<ll, ll> pll;
const ll N = 1e9 + 1;

vector<vector<pll>> adj;
vl dist, vis;
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijsktra()
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
                pq.push({dist[edge.ff], edge.ff});
            }
        }
    }
}

int main()
{
    fast;

    ll n, m, a, b, w;
    cin >> n >> m;

    adj.resize(n + 1), dist.resize(n + 1, N * m + 1LL), vis.resize(n + 1, 0);
    while (m--)
    {
        cin >> a >> b >> w;
        adj[a].pb({b, w});
    }

    dijsktra();
    f(1, n + 1, 1) cout << dist[i] << " ";

    return 0;
}