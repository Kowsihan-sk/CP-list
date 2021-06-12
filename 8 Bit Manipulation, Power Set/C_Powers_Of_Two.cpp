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

void solve(ll n, ll k)
{
    if (!(__builtin_popcountll(n) <= k && k <= n))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    priority_queue<ll> pq;
    f(0, 31, 1)
    {
        if (n & (1 << i))
            pq.push(1 << i);
    }
    while (!pq.empty() && pq.size() < k)
    {
        ll el = pq.top();
        pq.pop();
        pq.push(el / 2);
        pq.push(el / 2);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ", pq.pop();
    }
}

int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    solve(n, k);

    return 0;
}