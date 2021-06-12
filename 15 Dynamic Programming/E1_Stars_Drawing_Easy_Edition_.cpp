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
typedef vector<ll> vl;
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<vl> vll;

ll n, m;
vector<string> s, g;
vll r, a, b;
vl dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};

ll getd(ll i, ll j, ll k)
{
    ll dxk = dx[k], dyk = dy[k];
    ll result = 0;
    while (i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '*')
        result++, i += dxk, j += dyk;
    return result;
}

int main()
{
    fast;

    cin >> n >> m;
    s.resize(n);
    f(0, n, 1) cin >> s[i];

    r.resize(n + 1, vl(m + 1)), a.resize(n + 1, vl(m + 1)), b.resize(n + 1, vl(m + 1));
    ll count = 0;
    f(1, n - 1, 1)
    {
        fo(j, 1, m - 1, 1)
        {
            if (s[i][j] == '*')
            {
                bool around = true;
                fo(k, 0, 4, 1)
                    around = around && (s[i + dx[k]][j + dy[k]] == '*');
                if (around)
                {
                    r[i][j] = INT_MAX;
                    fo(k, 0, 4, 1)
                        r[i][j] = min(r[i][j], getd(i, j, k) - 1);
                    count++;
                    a[i][j - r[i][j]] = max(a[i][j - r[i][j]], 2 * r[i][j] + 1);
                    b[i - r[i][j]][j] = max(b[i - r[i][j]][j], 2 * r[i][j] + 1);
                }
            }
        }
    }

    g.resize(n, string(m, '.'));
    ll temp = 0;
    f(0, n, 1)
    {
        temp = 0;
        fo(j, 0, m, 1)
        {
            temp = max(temp - 1, a[i][j]);
            if (temp > 0)
                g[i][j] = '*';
        }
    }
    f(0, m, 1)
    {
        temp = 0;
        fo(j, 0, n, 1)
        {
            temp = max(temp - 1, b[j][i]);
            if (temp > 0)
                g[j][i] = '*';
        }
    }

    if (s == g)
    {
        cout << count << endl;
        f(0, n, 1)
        {
            fo(j, 0, m, 1)
            {
                if (r[i][j] > 0)
                    cout << i + 1 << " " << j + 1 << " " << r[i][j] << endl;
            }
        }
    }
    else
        cout << -1;

    return 0;
}