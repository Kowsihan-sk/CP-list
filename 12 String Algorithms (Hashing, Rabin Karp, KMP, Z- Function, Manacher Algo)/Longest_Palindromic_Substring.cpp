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

string manacherAlgo(string s)
{
    // change string to $#s#s#s#s#s@ to check for even too
    string str;
    str = '$';
    f(0, sz(s), 1) str += '#', str += s[i];
    str += "#@";

    // manacher algo in new string
    ll n = sz(str), c = 0, r = 0;
    vl p(n);

    f(1, n - 1, 1)
    {
        ll mirr = 2 * c - i;

        if (i < r)
            p[i] = min(r - i, p[mirr]);
        while (str[i + (1 + p[i])] == str[i - (1 + p[i])])
            p[i]++;
        if (i + p[i] > r)
            c = i, r = i + p[i];
    }

    ll index = 0, m = 0;
    f(2, n - 1, 1)
    {
        if (m < p[i])
            m = p[i], index = i - 2;
    }
    index = index / 2 - m / 2;
    if (!(m % 2))
        index++;
    return s.substr(index, m);
}

int main()
{
    fast;

    ll TT, m, index;
    string s;
    cin >> TT;

    while (TT--)
    {
        cin >> s;
        cout << manacherAlgo(s) << endl;
    }

    return 0;
}