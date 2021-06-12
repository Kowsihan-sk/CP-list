#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define Size(n) ((int)(n).size())
typedef vector<ll> vl;

ll solve(vl v, ll k, ll n)
{
    ll curr = 0, index = 0, cmin = INT_MAX;
    f(1, n + 1, 1)
    {
        if (i < k )
        {
            curr += v[i];
            continue;
        }
        curr += v[i] - v[i - k];
        if (curr < cmin)
        {
            // cout << i << " " << curr << " " << cmin << endl;
            cmin = curr;
            index = i - k + 1;
        }
    }
    // index++;
    return index;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vl v(n + 1);
    f(1, n + 1, 1) cin >> v[i];
    cout << solve(v, k, n) << endl;

    return 0;
}