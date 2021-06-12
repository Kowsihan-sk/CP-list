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

struct triplet
{
    ll a, b, w;
};

ll n, m;
vector<triplet> edges;
vl dist, relaxant;

void bellman_ford()
{
    ll x;
    f(1, n + 1, 1)
    {
        x = -1;
        for (auto e : edges)
        {
            ll u = e.a, v = e.b, d = e.w;

            if (dist[u] + d < dist[v])
            {
                dist[v] = dist[u] + d;
                relaxant[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO" << endl;
        return;
    }

    f(0, n - 1, 1) x = relaxant[x];

    vl cycle;
    for (ll v = x;; v = relaxant[v])
    {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1)
            break;
    }

    reverse(cycle.begin(), cycle.end());
    cout << "YES\n";
    for (ll v : cycle)
        cout << v << " ";
}

int main()
{
    fast;
    cin >> n >> m;

    dist.resize(n + 1), relaxant.resize(n + 1, -1), edges.resize(m);
    triplet inp;
    f(0, m, 1)
    {
        cin >> inp.a >> inp.b >> inp.w;
        edges[i] = inp;
    }

    bellman_ford();

    return 0;
}