#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vll;
typedef vector<vll> vllll;

int main()
{
    ll n, m, u, q;
    cin >> n >> m >> u >> q;

    vllll a(n);
    fo(i, 0, n)
    {
        a[i] = vll(m);
        fo(j, 0, m)
        {
            cin >> a[i][j];
        }
    }

    vllll diff(n);
    fo(i, 0, n)
    {
        diff[i] = vll(m + 1);
        diff[i][0] = a[i][0];
        diff[i][m] = 0;
        fo(j, 1, m)
        {
            diff[i][j] = a[i][j] - a[i][j - 1];
        }
    }

    while (u--)
    {
        ll r1, c1, r2, c2, k;
        cin >> k >> r1 >> c1 >> r2 >> c2;

        if (r1 > r2)
            swap(r1, r2);
        if (c1 > c2)
            swap(c1, c2);

        fo(i, r1, r2 + 1)
        {
            diff[i][c1] += k;
            diff[i][c2 + 1] -= k;
        }
    }

    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (j == 0)
                a[i][j] = diff[i][j];
            else
                a[i][j] = diff[i][j] + a[i][j - 1];
        }
    }

    vllll p_sum(n);
    fo(i, 0, n)
    {
        p_sum[i] = vll(m);
        fo(j, 0, m)
        {
            if (i == 0 && j == 0)
                p_sum[i][j] = a[i][j];
            else if (i == 0)
                p_sum[i][j] = p_sum[i][j - 1] + a[i][j];
            else if (j == 0)
                p_sum[i][j] = p_sum[i - 1][j] + a[i][j];
            else
                p_sum[i][j] = p_sum[i - 1][j] + p_sum[i][j - 1] + a[i][j] - p_sum[i - 1][j - 1];
        }
    }

    while (q--)
    {
        ll r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        ll sum = 0;
        sum = p_sum[r2][c2];
        if (c1 - 1 >= 0)
            sum -= p_sum[r2][c1 - 1];
        if (r1 - 1 >= 0)
            sum -= p_sum[r1 - 1][c2];
        if (r1 - 1 >= 0 && c1 - 1 >= 0)
            sum += p_sum[r1 - 1][c1 - 1];
        cout << sum << endl;
    }

    return 0;
}