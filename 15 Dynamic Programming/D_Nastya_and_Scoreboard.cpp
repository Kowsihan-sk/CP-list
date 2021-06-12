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
#define pb push_back
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)
typedef vector<vl> vll;

vector<string> digit;
// vector<vector<vector<int>>> dp(2005, vector<vector<int>>(2005, vector<int>(11, -1)));
// vector<vector<int>> changes(2005, vector<int>(10));
int dp[2005][2005][11], changes[2005][10];
ll n, k;
string ans = "";

void digit_init()
{
    f(0, 10, 1) digit.pb("01111111");

    // zero
    digit[0][4] = '0';
    // one
    digit[1][1] = digit[1][2] = digit[1][4] = digit[1][5] = digit[1][7] = '0';
    // two
    digit[2][2] = digit[2][6] = '0';
    // three
    digit[3][2] = digit[3][5] = '0';
    // four
    digit[4][1] = digit[4][5] = digit[4][7] = '0';
    // five
    digit[5][3] = digit[5][5] = '0';
    // six
    digit[6][3] = '0';
    // seven
    digit[7][2] = digit[7][4] = digit[7][5] = digit[7][7] = '0';
    // nine
    digit[9][5] = '0';
}

ll compute(ll ind, ll sum, ll num)
{
    if (ind == n)
    {
        if (sum == 0)
            return dp[ind][sum][num] = 1;
        return dp[ind][sum][num] = 0;
    }

    if (dp[ind][sum][num] != -1)
        return dp[ind][sum][num];

    ll maxi = 0;
    fd(9, 0, 1)
    {
        ll cnt = changes[ind][i];
        if (cnt != -1 && cnt <= sum)
            maxi = max(maxi, compute(ind + 1, sum - cnt, i));
    }
    return dp[ind][sum][num] = maxi;
}

void findans(ll ind, ll sum)
{
    if (ind == n)
        return;

    fd(9, 0, 1)
    {
        ll cnt = changes[ind][i];
        if (cnt != -1 && cnt <= sum && dp[ind + 1][sum - cnt][i] == 1)
        {
            char c = 48 + i;
            ans += c;
            findans(ind + 1, sum - cnt);
            return;
        }
    }
}

int main()
{
    fast;

    cin >> n >> k;
    vector<string> ar(n);
    f(0, n, 1)
    {
        string s;
        cin >> s;
        ar[i] = '0' + s;
    }

    // dp.resize(n + 1, vector<vector<int>>(k + 1, vector<int>(10, -1)));
    // changes.resize(n + 1, vector<int>(10));
    memset(dp, -1, sizeof(dp));
    digit_init();

    fo(ind, 0, n, 1)
    {
        fd(9, 0, 1)
        {
            ll cnt = 0;
            string s1 = digit[i], s2 = ar[ind];
            fo(j, 1, 8, 1)
            {
                if (s1[j] == '1' && s2[j] == '0')
                    cnt++;
                else if (s1[j] == '0' && s2[j] == '1')
                {
                    cnt = -1;
                    break;
                }
            }
            changes[ind][i] = cnt;
        }
    }

    ll val = compute(0, k, 0);
    findans(0, k);

    if (sz(ans))
        cout << ans;
    else
        cout << -1;

    return 0;
}
