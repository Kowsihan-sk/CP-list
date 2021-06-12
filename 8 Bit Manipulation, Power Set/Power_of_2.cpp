/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define endl "\n"

bool isPow_of2(ll n)
{
    return (n && (!(n & (n - 1))));
}

int main()
{
    fast;
    ll TT;
    cin >> TT;

    ll count = 0;
    while (TT--)
    {
        ll n;
        cin >> n;
        if (isPow_of2(n))
            count++;
    }
    cout << count << endl;

    return 0;
}