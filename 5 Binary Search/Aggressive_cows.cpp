/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;

ll max_pos_dist(ll cow, vl v)
{
    sort(all(v));
    ll low = 1, high = v[Size(v) - 1] - v[0];

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll prev = v[0], ncows = 1;
        f(1, Size(v), 1)
        {
            if (v[i] - prev >= mid)
            {
                ncows++;
                prev = v[i];
            }
            if (ncows >= cow)
                break;
        }
        if (ncows >= cow)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    int TT;
    cin >> TT;

    while (TT--)
    {
        ll n, cow;
        cin >> n >> cow;

        vl v(n);
        f(0, n, 1) cin >> v[i];

        cout << max_pos_dist(cow, v) << endl;
    }

    return 0;
}