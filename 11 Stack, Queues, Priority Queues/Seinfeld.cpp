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
#define pb push_back

ll minOpBalanced(string s)
{
    stack<char> st;
    f(0, sz(s), 1)
    {
        if (s[i] == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else
            st.push(s[i]);
    }
    if (st.empty())
        return 0;
    char el = '{';
    ll m = 0, t = st.size();
    while (!st.empty() && st.top() == '{')
        m++, st.pop();
    return (t / 2 + m % 2);
}

int main()
{
    fast;

    vector<string> s;
    string x;
    while (cin >> x)
        s.pb(x);
    ll int tt = 1;

    f(0, sz(s) - 1, 1)
    {
        cout << tt << ". " << minOpBalanced(s[i]) << endl;
        tt++;
    }

    return 0;
}