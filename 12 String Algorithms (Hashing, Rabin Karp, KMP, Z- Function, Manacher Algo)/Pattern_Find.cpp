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

vl calcPrefixArKMP(string pat)
{
    ll patLen = sz(pat);
    vl ar(patLen + 1);
    ar[0] = -1, ar[1] = 0;
    ll prefixLen = 0, i = 1;
    while (i < patLen)
    {
        if (pat[i] == pat[prefixLen])
        {
            i++, prefixLen++;
            ar[i] = prefixLen;
        }
        else if (prefixLen > 0)
            prefixLen = pat[prefixLen];
        else
            i++, ar[i] = 0;
    }
    return ar;
}

vl KMPSearch(string s, string pat)
{
    ll t = 0, p = 0;
    ll tLen = sz(s), pLen = sz(pat);
    vl prefixAr = calcPrefixArKMP(pat);
    vl count;
    while (t < tLen)
    {
        if (s[t] == pat[p])
        {
            t++, p++;
            if (p == pLen)
                count.pb((t - p) + 1);
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
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll TT;
    cin >> TT;

    string text, pattern;
    while (TT--)
    {
        cin >> text >> pattern;
        vl count = KMPSearch(text, pattern);
        if (!count.empty())
        {
            cout << count.size() << endl;
            f(0, sz(count), 1) cout << count[i] << " ";
            cout << "\n\n";
        }
        else
            cout << "Not Found"
                 << "\n\n";
    }

    return 0;
}