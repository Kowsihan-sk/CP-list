/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define endl "\n"
typedef vector<ll> vl;

void solve(ll n)
{
    set<ll> s;
    for (ll i = 2; i * i <= n; i++)
    {
        if (!(n % i))
        {
            s.insert(i), n /= i;
            break;
        }
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (!(n % i) && !s.count(i))
        {
            s.insert(i), n /= i;
            break;
        }
    }
    if (s.size() < 2 || s.count(n) || n == 1)
        cout << "NO";
    else
    {
        s.insert(n);
        cout << "YES\n";
        for (auto it : s)
            cout << it << " ";
    }
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll TT;
    cin >> TT;

    while (TT--)
    {
        ll n;
        cin >> n;
        solve(n);
        cout << endl;
    }

    return 0;
}