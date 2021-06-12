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
#define pb push_back
#define all(n) (n).begin(), (n).end()

ll meet_in_the_middle(vl v, ll n, ll k)
{
    vl v1, v2;
    f(0, n / 2, 1) v1.pb(v[i]);
    f(n / 2, n, 1) v2.pb(v[i]);

    ll n1 = (n / 2), n2 = (n - (n / 2));
    vl s1, s2;
    for (ll i = 0; i < (1 << n1); i++)
    {
        ll sum = 0;
        for (ll j = 0; j < n1; j++)
        {
            if (i & (1 << j))
                sum += v1[j];
        }
        s1.pb(sum);
    }
    for (ll i = 0; i < (1 << n2); i++)
    {
        ll sum = 0;
        for (ll j = 0; j < n2; j++)
        {
            if (i & (1 << j))
                sum += v2[j];
        }
        s2.pb(sum);
    }
    sort(all(s2));
    ll ans = 0;
    for (int i = 0; i < (1 << n1); i++)
    {
        if (s1[i] <= k)
        {
            ll temp = k - s1[i];
            ll lb = lower_bound(all(s2), temp) - s2.begin();
            if (lb == (1 << n2) || (s2[lb] != temp))
                continue;
            ll ub = upper_bound(all(s2), temp) - s2.begin();
            ub--;
            ans += (ub - lb + 1);
        }
    }

    return ans;
}

int main()
{
    fast;

    ll n, k;
    cin >> n >> k;
    vl v(n);
    f(0, n, 1) cin >> v[i];
    cout << meet_in_the_middle(v, n, k);

    return 0;
}