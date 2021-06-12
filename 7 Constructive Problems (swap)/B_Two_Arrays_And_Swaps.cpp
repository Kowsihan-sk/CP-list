/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;

ll solve(vl &a, vl &b, ll k)
{
    ll n = Size(a);
    sort(all(a));
    sort(all(b));
    reverse(all(b));

    for (ll i = 0; i < n && i < k; i++)
    {
        if (a[i] < b[i])
            swap(a[i], b[i]);
        else
            break;
    }
    ll sum = 0;
    f(0, n, 1) sum += a[i];

    return sum;
}

int main()
{
    fast;
    ll TT;
    cin >> TT;

    while (TT--)
    {
        ll n, k;
        cin >> n >> k;

        vl a(n), b(n);
        f(0, n, 1) cin >> a[i];
        f(0, n, 1) cin >> b[i];

        cout << solve(a, b, k) << "\n";
    }

    return 0;
}