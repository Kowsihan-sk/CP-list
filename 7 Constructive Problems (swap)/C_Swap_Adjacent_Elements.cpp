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

string solve(vl arr, string pos, ll n)
{
    ll maxi = 0;
    f(0, n, 1)
    {
        maxi = max(maxi, arr[i]);
        if (pos[i] == '0' && maxi > i + 1)
            return "NO";
    }
    return "YES";
}
int main()
{
    fast;
    ll n;
    cin >> n;
    vl arr(n);
    f(0, n, 1) cin >> arr[i];
    string pos;
    cin >> pos;
    cout << solve(arr, pos, n) << endl;

    return 0;
}