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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define Size(n) ((int)(n).size())
typedef vector<ll> vl;
#define pb push_back
#define ff first
#define ss second
typedef pair<ll, ll> pll;

void solve(vl arr, ll n)
{
    vector<pll> swaps;
    f(0, n, 1)
    {
        ll min = i;
        fo(j, i + 1, n, 1)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swaps.pb(make_pair(i, min));
        swap(arr[i], arr[min]);
    }
    cout << Size(swaps) << endl;
    f(0, Size(swaps), 1) cout << swaps[i].ff << " " << swaps[i].ss << endl;
}

int main()
{
    fast;
    ll n;
    cin >> n;

    vl arr(n);
    f(0, n, 1) cin >> arr[i];
    solve(arr, n);

    return 0;
}