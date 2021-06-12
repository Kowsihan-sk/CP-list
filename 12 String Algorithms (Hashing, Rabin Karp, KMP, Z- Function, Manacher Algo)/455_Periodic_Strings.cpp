/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

// #define fast                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);
#define ll long long
#define endl "\n"
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define sz(n) ((int)(n).size())

bool isKPeriodic(string s, ll k)
{
    f(k, sz(s), 1) if (s[i] != s[i % k]) return false;
    return true;
}
int solve(string s)
{
    f(1, sz(s) + 1, 1)
    {
        if (sz(s) % i)
            continue;
        if (isKPeriodic(s, i))
            return i;
    }
    return sz(s);
}

int main()
{
    // fast;

    int TT;
    scanf("%d\n", &TT);
    // cin >> TT;

    string s;
    while (TT--)
    {
        cin >> s;
        int ans = solve(s);
        // cout << solve(s) << "\n\n";
        printf("%d\n", ans);
        if (TT)
            printf("\n");
    }

    return 0;
}