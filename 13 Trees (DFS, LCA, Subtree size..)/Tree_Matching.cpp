/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define sz(n) ((int)(n).size())
typedef vector<ll> vl;
#define pb push_back
typedef vector<vl> vll;

vll tree;
vl used;
ll max_matching = 0;
void matching_dfs(ll src, ll par)
{
    for (ll child : tree[src])
    {
        if (child != par)
            matching_dfs(child, src);
    }
    if (!used[src] && !used[par] && par)
        max_matching++, used[src] = used[par] = 1;
}

void solve_greedy()
{
    matching_dfs(1, 0);
    cout << max_matching;
}

int main()
{
    fast;

    ll n, x, y;
    cin >> n;
    tree.resize(n + 1);
    used.resize(n + 1);
    f(1, n, 1)
    {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    solve_greedy();

    return 0;
}