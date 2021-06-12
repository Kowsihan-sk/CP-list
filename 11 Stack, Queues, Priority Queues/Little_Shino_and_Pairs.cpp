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
typedef vector<ll> vl;
#define pb push_back
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)

ll solve(vl ar, ll n)
{
    ll count = 0;
    vl st;
    // from left to right
    st.pb(ar[0]);
    f(1, n, 1)
    {
        while (!st.empty() && st.back() <= ar[i])
            st.pop_back();
        if (!st.empty() && st.back() > ar[i])
            count++;
        st.pb(ar[i]);
    }
    st.clear();
    // right to left
    st.pb(ar[n - 1]);
    fd(n - 2, 0, 1)
    {
        while (!st.empty() && st.back() <= ar[i])
            st.pop_back();
        if (!st.empty() && st.back() > ar[i])
            count++;
        st.pb(ar[i]);
    }
    return count;
}

int main()
{
    fast;

    ll n;
    cin >> n;
    vl ar(n);
    f(0, n, 1) cin >> ar[i];
    cout << solve(ar, n);

    return 0;
}