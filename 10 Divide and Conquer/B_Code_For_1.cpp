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

ll cnt(ll temp)
{
    ll x = 1;
    while (temp > 1)
    {
        temp /= 2;
        x *= 2;
    }
    return x;
}
ll is_one(ll pos, ll target, ll num)
{
    if (num < 2)
        return num;
    if (pos + 1 == 2LL * target)
        return num % 2;
    num /= 2;
    pos /= 2;
    if (target > pos + 1)
        target -= (pos + 1);
    return is_one(pos, target, num);
}
ll solve(ll n, ll l, ll r)
{
    ll count = 0, length = 2LL * cnt(n) - 1LL;
    f(l, r + 1, 1)
    {
        count += is_one(length, i, n);
    }

    return count;
}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll T = 2;
    while (T--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        cout << solve(n, l, r) << endl;
    }

    return 0;
}