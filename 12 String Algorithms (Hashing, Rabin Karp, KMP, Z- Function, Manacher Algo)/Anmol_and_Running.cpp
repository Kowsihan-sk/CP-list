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

vl calcPrefixArKMP(vl s)
{
    ll patLen = sz(s);
    vl arr(patLen + 1);
    arr[0] = -1, arr[1] = 0;
    ll prefixLen = 0, i = 1;

    while (i < patLen)
    {
        if (s[prefixLen] == s[i])
        {
            i++, prefixLen++;
            arr[i] = prefixLen;
        }
        else if (prefixLen > 0)
            prefixLen = arr[prefixLen];
        else
            i++, arr[i] = 0;
    }
    return arr;
}

ll KMPSearch(vl s, vl pat)
{
    ll t = 0, p = 0, count = 0;
    ll tLen = sz(s), pLen = sz(pat);
    vl prefixAr = calcPrefixArKMP(pat);
    while (t < tLen)
    {
        if (s[t] == pat[p])
        {
            t++, p++;
            if (p == pLen)
                count++;
        }
        else
        {
            p = prefixAr[p];
            if (p < 0)
                t++, p++;
        }
    }
    return count;
}

ll solve(vl p, vl d)
{
    vl diff(sz(p) - 1);
    f(0, sz(p) - 1, 1) diff[i] = p[i + 1] - p[i];
    return KMPSearch(diff, d);
}

int main()
{
    fast;

    ll TT;
    cin >> TT;

    ll n, k;
    vl p, d;
    while (TT--)
    {
        cin >> n >> k;
        p.resize(n), d.resize(k);
        f(0, n, 1) cin >> p[i];
        f(0, k, 1) cin >> d[i];
        cout << solve(p, d) << endl;
    }

    return 0;
}