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

string isBalanced(string s)
{
    stack<char> st;
    f(0, sz(s), 1)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (!st.empty() && abs((ll)s[i] - (ll)st.top()) <= 2)
                st.pop();
            else
                return "NO";
        }
    }
    if (st.size())
        return "NO";
    return "YES";
}
int main()
{
    fast;

    ll TT;
    cin >> TT;

    string s;
    while (TT--)
    {
        cin >> s;
        cout << isBalanced(s) << endl;
    }

    return 0;
}