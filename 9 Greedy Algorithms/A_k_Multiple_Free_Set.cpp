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
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;

ll solve(vl v, ll n, ll k)
{
    set<ll> s;
    sort(all(v));
    f(0, n, 1)
    {
        if (v[i] % k)
            s.insert(v[i]);
        else if (!(s.count(v[i] / k)))
            s.insert(v[i]);
    }

    return s.size();
}

int main()
{
    fast;

    ll n, k;
    cin >> n >> k;
    vl v(n);
    f(0, n, 1) cin >> v[i];
    cout << solve(v, n, k);

    return 0;
}