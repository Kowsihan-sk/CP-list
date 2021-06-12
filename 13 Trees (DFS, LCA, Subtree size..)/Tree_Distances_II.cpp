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
vl ans, subtreeSize, subtreeAns;
void preprocessing(ll node, ll par = 0)
{
    ll no_nodes = 1, ans_subtree = 0;
    for (ll child : adj[node])
    {
        if (child != par)
        {
            preprocessing(child, node);
            no_nodes += subtreeSize[child];
            ans_subtree += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[node] = no_nodes;
    subtreeAns[node] = ans_subtree;
}

void solve(ll node, ll par, ll par_ans, ll total_nodes)
{
    ans[node] = subtreeAns[node] + (par_ans + (total_nodes - subtreeSize[node]));

    for (ll child : adj[node])
    {
        if (child != par)
        {
            solve(child, node, ans[node] - (subtreeSize[child] + subtreeAns[child]), total_nodes);
        }
    }
}

int main()
{
    fast;

    ll n, a, b;
    cin >> n;
    adj.resize(n + 1), subtreeAns.resize(n + 1), subtreeSize.resize(n + 1), ans.resize(n + 1);
    f(1, n, 1) cin >> a >> b, adj[a].pb(b), adj[b].pb(a);

    preprocessing(1);
    solve(1, 0, 0, n);
    f(1, n + 1, 1) cout << ans[i] << " ";

    return 0;
}