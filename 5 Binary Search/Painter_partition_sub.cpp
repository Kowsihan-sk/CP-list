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

ll paint_partition(ll A, ll B, vl C)
{
    const int mod = 10000003;
    long long start = 0, end = 0, ans = LONG_MAX;
    for (long long i = 0; i < C.size(); i++)
    {
        end += C[i];
        if (C[i] > start)
            start = C[i];
    }

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        bool flag = false;
        long long npainter = 1, prev = C[0];

        for (long long i = 1; i < C.size(); i++)
        {
            if (prev + C[i] > mid)
            {
                prev = C[i];
                npainter++;
            }
            else
                prev += C[i];
        }
        if (npainter <= A)
            flag = true;

        if (flag)
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