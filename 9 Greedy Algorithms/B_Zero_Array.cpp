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

string solve(vl v, ll n)
{
    ll sum = accumulate(all(v), 0LL);
    ll max_e = *max_element(all(v));
    max_e = sum - max_e - max_e;
    if (max_e >= 0 && !(sum % 2))
        return "YES";
    return "NO";
}

int main()
{
    fast;

    ll n;
    cin >> n;
    vl v(n);
    f(0, n, 1) cin >> v[i];
    cout << solve(v, n) << endl;

    return 0;
}