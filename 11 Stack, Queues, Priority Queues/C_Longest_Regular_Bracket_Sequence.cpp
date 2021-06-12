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

void solve(string s)
{
    ll len = 0, no_of_such_seq = 0;
    vector<char> charst;
    vl indexst;
    indexst.pb(-1);
    f(0, sz(s), 1)
    {
        if (s[i] == '(')
            charst.pb(s[i]), indexst.pb(i);
        else
        {
            if (!charst.empty())
            {
                charst.pop_back(), indexst.pop_back();
                len = max(len, i - indexst.back());
            }
            else
                indexst.pb(i);
        }
    }
    indexst.pb(sz(s));
    f(1, sz(indexst), 1)
    {
        if ((indexst[i] - indexst[i - 1] - 1) == len)
            no_of_such_seq++;
    }
    if (!len)
        cout << len << " " << 1 << endl;
    else
        cout << len << " " << no_of_such_seq << endl;
}

int main()
{
    fast;

    string s;
    cin >> s;
    solve(s);

    return 0;
}