#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

int main()
{
    ll n;
    cin >> n;

    vl a(n + 2), b(n + 2);

    ll q;
    ll l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
        b[r + 1] -= (r - l + 1);
    }

    fo(i, 1, n + 1)
        a[i] += a[i - 1];

    fo(i, 1, n + 1)
        b[i] += b[i - 1] + a[i];

    ll m;
    ll x;
    cin >> m;
    while (m--)
    {
        cin >> x;
        cout << b[x] << endl;
    }

    return 0;
}