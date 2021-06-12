#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<ll> vl;

void solve()
{
    ll n, a, b;
    cin >> n >> b >> a;

    vl v(n + 1);
    f(1, n + 1, 1) cin >> v[i];

    double ans = INT_MIN, curr = 0;
    fo(k, a, b + 1, 1)
    {
        curr = 0;
        f(1, n + 1, 1)
        {
            if (i < k)
            {
                curr += v[i];
                continue;
            }
            curr += v[i] - v[i - k];
            ans = max(ans, (double)curr / (k * 1.0));
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}