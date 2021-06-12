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
#define sz(n) ((int)(n).size())
typedef vector<ll> vl;
#define pb push_back
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)
#define all(n) (n).begin(), (n).end()

int main()
{
    fast;

    ll n;
    cin >> n;
    vl ar(n);

    f(0, n, 1) cin >> ar[i];
    map<ll, ll> dp;
    ll maxx = 0, maxx_num = 0;

    f(0, n, 1)
    {
        dp[ar[i]] = dp[ar[i] - 1] + 1;
        if (dp[ar[i]] > maxx)
        {
            maxx = dp[ar[i]];
            maxx_num = ar[i];
        }
    }

    cout << maxx << endl;
    vl ans;
    fd(n - 1, 0, 1)
    {
        if (ar[i] == maxx_num)
            maxx_num--, ans.pb(i + 1);
    }
    reverse(all(ans));

    f(0, sz(ans), 1) cout << ans[i] << " ";

    return 0;
}