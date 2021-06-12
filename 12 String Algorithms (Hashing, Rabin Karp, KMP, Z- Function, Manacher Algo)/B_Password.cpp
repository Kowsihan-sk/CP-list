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

vl calcPrefixArrKMP(string s)
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

string solve(string s)
{
    vl ar = calcPrefixArrKMP(s);
    vl vis(sz(ar));
    ll n = sz(s), t = ar[n];

    f(1, n, 1) vis[ar[i]] = 1;
    while (t > 0)
    {
        cout << t << " ";
        if (vis[t])
            return s.substr(0, t);
        t = ar[t];
    }

    return "Just a legend";
}

int main()
{
    fast;

    string s;
    cin >> s;
    cout << solve(s);

    return 0;
}