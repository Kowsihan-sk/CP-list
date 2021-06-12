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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<vl> vll;
const ll N = 1e15;

vll dist;
ll n, m, q;

void floyd_warshall()
{
    fo(k, 1, n + 1, 1)
    {
        f(1, n + 1, 1)
        {
            fo(j, 1, n + 1, 1)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    fast;

    cin >> n >> m >> q;

    dist.resize(n + 1, vl(n + 1, N));
    f(0, n + 1, 1) dist[i][i] = 0;

    ll u, v, w;
    f(0, m, 1)
    {
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }

    floyd_warshall();

    f(0, q, 1)
    {
        cin >> u >> v;
        if (dist[u][v] == N)
            dist[u][v] = -1;
        cout << dist[u][v] << endl;
    }

    return 0;
}