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

void solve(ll n)
{
    ll x = ceil(sqrt(n));
    ll y = n / x;
    cout << x + y << endl;
    f(0, x, 1) cout << i << " ";
    fd(y, 1, 1) cout << n / i << " ";
    cout << endl;
}
int main()
{
    fast;

    ll TT;
    cin >> TT;

    while (TT--)
    {
        ll n;
        cin >> n;
        solve(n);
    }

    return 0;
}