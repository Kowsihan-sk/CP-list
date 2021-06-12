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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<vl> vll;

vll adj;
vl col;
ll n;

bool isBipartite(ll node)
{
    queue<ll> q;
    q.push(node);
    col[node] = 0;

    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();

        for (ll el : adj[cur])
        {
            if (col[el] == col[cur])
                return false;
            if (col[el] == -1)
            {
                col[el] = 1 - col[cur];
                q.push(el);
            }
        }
    }

    return true;
}

int main()
{
    fast;

    string s;
    cin >> n >> s;

    adj.resize(n);
    col.resize(n + 1, -1);

    f(0, n, 1)
    {
        fo(j, i + 1, n, 1)
        {
            if (s[i] > s[j])
            {
                adj[i].pb(j), adj[j].pb(i);
            }
        }
    }

    f(0, n, 1)
    {
        if (col[i] == -1)
            if (!isBipartite(i))
            {
                cout << "NO\n";
                return 0;
            }
    }

    cout << "YES\n";
    f(0, n, 1) cout << col[i];

    return 0;
}