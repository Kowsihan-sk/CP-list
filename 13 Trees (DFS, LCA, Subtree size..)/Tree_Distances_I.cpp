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
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)
typedef vector<ll> vl;
#define sz(n) ((int)(n).size())
#define pb push_back
typedef vector<vl> vll;

vll adj;
vl vis;
ll maxD;
void dfs(ll node, ll d);
void O_NSquare_soln();

vll tree;
vl ans, depth;
void eval_depth(ll src, ll par)
{
    ll src_depth = 0;
    for (ll child : tree[src])
    {
        if (child != par)
        {
            eval_depth(child, src);
            src_depth = max(src_depth, 1 + depth[child]);
        }
    }
    depth[src] = src_depth;
}

void solve(ll src, ll par, ll par_ans)
{
    vl prefixMax, suffixMax;
    // getting depth of child nodes
    for (ll child : tree[src])
    {
        if (child != par)
            prefixMax.pb(depth[child]), suffixMax.pb(depth[child]);
    }
    // making it prefix and suffix max
    f(1, sz(prefixMax), 1) prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);
    fd(sz(suffixMax) - 2, 0, 1) suffixMax[i] = max(suffixMax[i], suffixMax[i + 1]);

    // ans for every child c_no
    ll c_no = 0;
    for (ll child : tree[src])
    {
        if (child != par)
        {
            ll op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
            ll op2 = (c_no == (sz(suffixMax) - 1)) ? INT_MIN : suffixMax[c_no + 1];
            ll partial_ans = 1 + max({par_ans, op1, op2});

            solve(child, src, partial_ans);
            c_no++;
        }
    }
    // eval ans for src
    ans[src] = 1 + max(par_ans, (prefixMax.empty()) ? -1 : prefixMax.back());
}

int main()
{
    fast;
    // O_NSquare_soln();

    ll n, a, b;
    cin >> n;
    tree.resize(n + 1);
    depth.resize(n + 1);
    ans.resize(n + 1);
    f(1, n, 1) cin >> a >> b, tree[a].pb(b), tree[b].pb(a);
    eval_depth(1, 0);
    solve(1, 0, -1);
    f(1, n + 1, 1) cout << ans[i] << " ";

    return 0;
}

void dfs(ll node, ll d)
{
    vis[node] = 1;
    if (d > maxD)
        maxD = d;
    for (ll child : adj[node])
    {
        if (vis[child] == 0)
            dfs(child, d + 1);
    }
}

void O_NSquare_soln()
{
    ll n, a, b;
    cin >> n;
    adj.resize(n + 1);
    vis.resize(n + 1);
    f(1, n, 1) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);
    f(1, n + 1, 1)
    {
        vis.assign(vis.size(), 0);
        maxD = -1;
        dfs(i, 0);
        cout << maxD << " ";
    }
}
