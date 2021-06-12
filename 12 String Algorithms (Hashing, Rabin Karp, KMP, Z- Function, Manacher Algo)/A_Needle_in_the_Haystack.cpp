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

vl calcPrefixArKMP(string pat)
{
    ll patLen = sz(pat);
    vl ar(patLen + 1);
    ar[0] = -1, ar[1] = 0;

    ll prefixLen = 0, i = 1;
    while (i < patLen)
    {
        if (pat[prefixLen] == pat[i])
        {
            prefixLen++, i++;
            ar[i] = prefixLen;
        }
        else if (prefixLen > 0)
            prefixLen = ar[prefixLen];
        else
            i++, ar[i] = 0;
    }
    return ar;
}

vector<ll> prefunction(string st)
{
    ll n = st.size();
    vector<ll> lps(n, 0);
    ll len = 0;
    ll i = 1;
    while (i < n)
    {
        if (st[i] == st[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - i];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void KMPSearch(string s, string pat)
{
    ll t = 0, p = 0;
    ll tLen = sz(s), pLen = sz(pat);
    vl prefixAr = calcPrefixArKMP(pat);

    while (t < tLen)
    {
        if (s[t] == pat[p])
        {
            t++, p++;
            if (p == pLen)
                cout << t - p << endl, p = prefixAr[p];
        }
        else
        {
            p = prefixAr[p];
            if (p < 0)
                t++, p++;
        }
    }
    return;
}

int main()
{
    fast;

    ll n;
    string text, pattern;
    while (cin >> n)
    {
        cin >> pattern >> text;
        KMPSearch(text, pattern);
        cout << endl;
    }

    return 0;
}