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
typedef vector<vl> vll;

vll adj;
vl vis;
ll maxD, maxNode;
void dfs(ll node, ll d)
{
    vis[node] = 1;
    if (d > maxD)
        maxD = d, maxNode = node;
    for (ll child : adj[node])
    {
        if (vis[child] == 0)
            dfs(child, d + 1);
    }
}

int main()
{
    fast;

    ll n, x, y;
    cin >> n;
    adj.resize(n + 1);
    vis.resize(n + 1);
    f(1, n, 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);

    // searching for farthest from root or any node
    maxD = -1;
    dfs(1, 0);
    // finding farthest node from previous farthest node
    vis.assign(vis.size(), 0);
    maxD = -1;
    dfs(maxNode, 0);

    cout << maxD;

    return 0;
}