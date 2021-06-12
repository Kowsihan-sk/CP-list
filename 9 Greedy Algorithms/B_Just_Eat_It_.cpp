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
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;

string solve(vl v, ll n)
{
    ll sum = 0;
    f(0, n, 1)
    {
        sum += v[i];
        if (sum <= 0)
            return "NO";
    }
    sum = 0;
    fd(n - 1, 0, 1)
    {
        sum += v[i];
        if (sum <= 0)
            return "NO";
    }
    return "YES";
}
string solve_kadane(vl v, ll n)
{
    ll meh = INT_MIN, msf = INT_MIN;
    ll sum = accumulate(all(v), 0LL);
    f(0, n - 1, 1)
    {
        meh = max(meh + v[i], v[i]);
        msf = max(msf, meh);
        if (msf >= sum)
            return "NO";
    }
    meh = INT_MIN, msf = INT_MIN;
    f(1, n, 1)
    {
        meh = max(meh + v[i], v[i]);
        msf = max(msf, meh);
        if (msf >= sum)
            return "NO";
    }
    return "YES";
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

        vl v(n);
        f(0, n, 1) cin >> v[i]; 
        cout << solve(v, n) << endl;
        // cout << solve_kadane(v, n) << endl;
    }

    return 0;
}
