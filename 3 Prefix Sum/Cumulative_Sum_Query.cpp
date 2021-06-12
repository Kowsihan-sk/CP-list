#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;

int main()
{
    int n;
    cin >> n;

    vi a(n), p_sum(n);
    fo(i, 0, n)
    {
        cin >> a[i];
        p_sum[i] = a[i];
        if (i > 0)
            p_sum[i] += p_sum[i - 1];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int sum = 0;
        if (l == 0)
            sum = p_sum[r];
        else
            sum = p_sum[r] - p_sum[l - 1];
        cout << sum << endl;
    }

    return 0;
}