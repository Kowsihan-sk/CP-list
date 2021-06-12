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

vll adj;
vl degree, ans;
priority_queue<ll, vl, greater<ll>> noInDeg;
ll n, m;

void topo_sort()
{
    f(1, n + 1, 1) if (!degree[i]) noInDeg.push(i);

    while (!noInDeg.empty())
    {
        ll u = noInDeg.top();
        noInDeg.pop();
        ans.pb(u);

        for (ll v : adj[u])
        {
            degree[v]--;
            if (!degree[v])
                noInDeg.push(v);
        }
    }
}

int main()
{
    fast;

    cin >> n >> m;

    adj.resize(n + 1), degree.resize(n + 1);
    ll a, b;
    f(0, m, 1) cin >> a >> b, adj[a].pb(b), degree[b]++;

    topo_sort();
    if (sz(ans) != n)
        cout << "IMPOSSIBLE";
    else
    {
        for (ll u : ans)
            cout << u << " ";
    }

    return 0;
}