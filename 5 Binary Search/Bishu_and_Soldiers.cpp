#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;

    vl v(n), psum(n);
    f(0, n, 1) cin >> v[i];
    sort(v.begin(), v.end());
    f(0, n, 1)
    {
        psum[i] = v[i];
        if (i)
            psum[i] += psum[i - 1];
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll power, count = 0, sum = 0;
        cin >> power;

        count = upper_bound(v.begin(), v.end(), power) - v.begin();
        count--;
        if (count < 0)
            cout << 0 << " " << 0 << endl;
        else
        {
            cout << count + 1 << " " << psum[count] << endl;
        }
    }

    return 0;
}