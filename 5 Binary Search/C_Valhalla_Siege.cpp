/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;

int main()
{
    ll n, q;
    cin >> n >> q;

    vl psum(n);
    f(0, n, 1)
    {
        cin >> psum[i];
        if (i > 0)
            psum[i] += psum[i - 1];
    }

    ll pow = 0, curr;
    while (q--)
    {
        ll hit;
        cin >> hit;
        pow += hit;
        curr = upper_bound(all(psum), pow) - psum.begin();
        if (curr == n)
            curr = pow = 0;
        cout << n - curr  << endl;
    }

    return 0;
}