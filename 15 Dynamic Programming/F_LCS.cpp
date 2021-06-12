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
#define sz(n) ((int)(n).size())
typedef vector<ll> vl;
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define all(n) (n).begin(), (n).end()
typedef vector<vl> vll;

string knapsack(string s, string t)
{
    string str = "";
    vll dp;
    ll n = sz(s), m = sz(t);
    dp.resize(n + 1, vl(m + 1));

    f(1, n + 1, 1)
    {
        fo(j, 1, m + 1, 1)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // finding string
    ll x = n, y = m;
    while (x && y)
    {
        if (dp[x][y] == dp[x][y - 1])
            y--;
        else if (dp[x][y] == dp[x - 1][y])
            x--;
        else
        {
            str += s[x - 1];
            x--, y--;
        }
    }
    // cout << dp[n][m] << endl;
    reverse(all(str));
    return str;
}

int main()
{
    fast;

    string s, t;
    cin >> s >> t;

    cout << knapsack(s, t);

    return 0;
}