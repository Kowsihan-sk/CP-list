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

vll tree;
void solve(ll src, ll par, vl &ans)
{
    ll subord = 0;
    for (ll child : tree[src])
    {
        if (child != par)
        {
            solve(child, src, ans);
            subord += (1 + ans[child]);
        }
    }
    ans[src] = subord;
}

int main()
{
    fast;

    ll n, x;

    cin >> n;
    vl ans(n + 1);
    tree.resize(n + 1);
    f(2, n + 1, 1)
    {
        cin >> x;
        tree[x].pb(i);
        tree[i].pb(x);
    }
    solve(1, 0, ans);
    f(1, n + 1, 1) cout << ans[i] << " ";

    return 0;
}