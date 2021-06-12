/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)
#define fdo(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;
typedef vector<vl> vll;
#define pb push_back
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 10000003;
const int N = (int)2 * 1e5 + 10;

bool isPossible(vl v, ll x, ll a)
{
    ll npainter = 1, prev = v[0];

    f(1, Size(v), 1)
    {
        if (prev + v[i] > x)
        {
            prev = v[i];
            npainter++;
        }
        else
            prev += v[i];
    }

    if (npainter <= a)
        return true;
    return false;
}

ll paint_partition(ll A, ll B, vl C)
{
    ll start = (ll)*max_element(all(C)), end = accumulate(all(C), 0), ans = LONG_MAX;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (isPossible(C, mid, A))
            end = mid - 1, ans = min(ans, mid);
        else
            start = mid + 1;
    }

    return ((ans % mod) * B) % mod;
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll n;
    cin >> n;

    vl v(n);
    f(0, n, 1) cin >> v[i];
    cout << paint_partition(a, b, v) << endl;

    return 0;
}