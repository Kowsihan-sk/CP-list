#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<ll> vll;

int main()
{
    int n;
    cin >> n;

    vll a(n);
    fo(i, 0, n)
    {
        cin >> a[i];
    }

    ll maxsum = 0, count = 0;
    fo(i, 0, n)
    {
        if (a[i] > 0)
        {
            maxsum += a[i];
            count++;
        }
    }
    if (count == 0)
    {
        maxsum = a[0];
        count++;
        fo(i, 1, n)
        {
            if (maxsum < a[i])
                maxsum = a[i];
        }
    }
    cout << maxsum << " " << count << endl;

    return 0;
}