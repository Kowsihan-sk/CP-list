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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)

int main()
{
    fast;

    ll n;
    cin >> n;

    vl ar(n);
    f(0, n, 1) cin >> ar[i];

    vl dp(n, INT_MAX);
    dp[0] = 0;

    f(0, n, 1)
    {
        fo(j, i + 1, i + 3, 1)
        {
            if (j < n)
                dp[j] = min(dp[j], dp[i] + abs(ar[j] - ar[i]));
        }
    }
    cout << dp[n - 1];

    return 0;
}