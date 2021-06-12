#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<ll> vll;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vll a(n);
        ll p_avg = 0;
        fo(i, 0, n)
        {
            cin >> a[i];
            if (a[i] != -1)
                p_avg += a[i];
            else
            {
                a[i] = p_avg / i;
                p_avg += a[i];
            }
        }

        fo(i, 0, n)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}