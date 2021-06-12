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

const ll INF = 1e17;
const ll NINF = INF * (-1);

struct triplet
{
    ll a, b, w;
};

ll n, m;
vector<triplet> edges;
vl dist;

void bellman_ford()
{
    dist[1] = 0;
    f(1, n, 1)
    {
        for (auto e : edges)
        {
            ll u = e.a, v = e.b, d = e.w;
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], d + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    }
    f(1, n, 1)
    {
        for (auto e : edges)
        {
            ll u = e.a, v = e.b, d = e.w;
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + d < dist[v])
                dist[v] = NINF;
        }
    }
}

int main()
{
    fast;
    cin >> n >> m;

    dist.resize(n + 1, INF), edges.resize(m);
    triplet inp;
    f(0, m, 1)
    {
        cin >> inp.a >> inp.b >> inp.w;
        inp.w *= -1;
        edges[i] = inp;
    }

    bellman_ford();
    if (dist[n] == NINF)
        cout << -1;
    else
        cout << dist[n] * (-1LL);

    return 0;
}