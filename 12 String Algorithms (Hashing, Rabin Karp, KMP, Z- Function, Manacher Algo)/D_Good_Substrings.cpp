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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)

ll solve(string s, string a, ll k)
{
    set<ll> x;
    ll count_bad = 0, count_hash = 0;
    f(0, sz(s), 1)
    {
        count_bad = count_hash = 0;
        fo(j, i, sz(s), 1)
        {
            if (a[s[j] - 'a'] == '0')
                count_bad++;
            if (count_bad > k)
                break;
            count_hash = (count_hash * 101) + (s[j] - 96);
            x.insert(count_hash);
        }
    }
    return x.size();
}

int main()
{
    fast;

    string s, a;
    ll k;
    cin >> s >> a;
    cin >> k;
    cout << solve(s, a, k) << endl;

    return 0;
}