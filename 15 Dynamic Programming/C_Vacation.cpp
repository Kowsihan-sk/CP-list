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
typedef vector<vl> vll;

vll ar, dp;
ll n;

ll func(ll day, ll flag)
{
    if (day == n)
        return 0;

    if (dp[day][flag] != -1)
        return dp[day][flag];

    ll maxi = 0;
    if (!flag)
    {
        maxi = max(maxi, ar[day][0] + func(day + 1, 1));
        maxi = max(maxi, ar[day][1] + func(day + 1, 2));
        maxi = max(maxi, ar[day][2] + func(day + 1, 3));
    }
    else if (flag == 1)
    {
        maxi = max(maxi, ar[day][1] + func(day + 1, 2));
        maxi = max(maxi, ar[day][2] + func(day + 1, 3));
    }
    else if (flag == 2)
    {
        maxi = max(maxi, ar[day][0] + func(day + 1, 1));
        maxi = max(maxi, ar[day][2] + func(day + 1, 3));
    }
    else
    {
        maxi = max(maxi, ar[day][0] + func(day + 1, 1));
        maxi = max(maxi, ar[day][1] + func(day + 1, 2));
    }

    return dp[day][flag] = maxi;
}

int main()
{
    fast;

    cin >> n;
    ar.resize(n, vl(3));
    dp.resize(n, vl(4, -1));

    f(0, n, 1) cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    cout << func(0, 0);

    return 0;
}