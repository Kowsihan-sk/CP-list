#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(a, b, c) for (ll i = a; i < b; i += c)
#define Size(n) ((int)(n).size())
typedef vector<ll> vl;

ll solve(queue<ll> q, vector<ll> v)
{
    ll time = 0;
    fo(0, Size(v), 1)
    {
        while (q.front() != v[i])
        {
            q.push(q.front());
            time++;
            q.pop();
        }
        q.pop();
        time++;
    }

    return time;
}

int main()
{
    ll n, i;
    cin >> n;

    queue<ll> q;
    vector<ll> a(n);
    while (q.size() < n && cin >> i)
        q.push(i);
    fo(0, n, 1) cin >> a[i];
    cout << solve(q, a) << endl;

    return 0;
}