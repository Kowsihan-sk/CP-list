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
#define all(n) (n).begin(), (n).end()

struct edge
{
    ll a, b, w;
};

vector<edge> ar;
vl par;

bool comp(edge a, edge b)
{
    if (a.w < b.w)
        return true;
    return false;
}

ll find(ll a)
{
    if (par[a] == -1)
        return a;
    return par[a] = find(par[a]);
}

void merge(ll a, ll b)
{
    par[a] = b;
}

int main()
{
    fast;

    ll n, m, a, b;
    cin >> n >> m;

    ar.resize(m), par.resize(n + 1, -1);
    f(0, m, 1) cin >> ar[i].a >> ar[i].b >> ar[i].w;

    sort(all(ar), comp);

    ll sum = 0;
    f(0, m, 1)
    {
        a = find(ar[i].a);
        b = find(ar[i].b);

        if (a != b)
            sum += ar[i].w, merge(a, b);
    }
    cout << sum;

    return 0;
}