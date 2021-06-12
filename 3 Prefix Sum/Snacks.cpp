#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<ll> vl;

int main()
{
    ll n;
    cin >> n;

    vl a(n), b(n + 2);
    fo(i, 0, n)
    {
        cin >> a[i];
        if (i > 0)
            b[i] = a[i] + b[i - 1];
        else
            b[i] = a[i];
    }

    ll t;
    cin >> t;

    vl c(t);
    fo(i, 0, t)
    {
        cin >> c[i];
    }

    fo(j, 0, t)
    {
        fo(i, 0, n)
        {
            if (b[i] >= c[j])
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}