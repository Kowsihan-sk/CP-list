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
#define ff first
#define ss second
typedef pair<ll, ll> pll;

int main()
{
    fast;

    ll n, m, a, b;

    cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    vl vis(n + 1);
    f(0, m, 1) cin >> a >> b, adj[a].pb({b, 0}), adj[b].pb({a, 1});

    ll m_cost = -1;
    deque<pll> q;
    q.push_front({1, 0});

    while (!q.empty())
    {
        ll u = q.front().ff, cost = q.front().ss;
        q.pop_front();

        if (u == n)
        {
            m_cost = cost;
            break;
        }
        if (vis[u])
            continue;
        vis[u] = 1;
        for (pll child : adj[u])
        {
            if (!vis[child.ff])
            {

                if (child.ss)
                    q.push_back({child.ff, cost + child.ss});
                else
                    q.push_front({child.ff, cost + child.ss});
            }
        }
    }
    cout << m_cost << endl;

    return 0;
}