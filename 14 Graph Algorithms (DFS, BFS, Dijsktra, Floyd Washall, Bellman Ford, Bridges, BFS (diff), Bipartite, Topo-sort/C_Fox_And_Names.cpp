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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<vl> vll;

vll graph(26);
vl degree(26);
priority_queue<ll, vl, greater<ll>> noInDeg;
vector<char> ans;
vector<string> s;

void topo_sort()
{
    f(0, 26, 1) if (!degree[i]) noInDeg.push(i);

    while (!noInDeg.empty())
    {
        ll u = noInDeg.top();
        noInDeg.pop();
        ans.pb((char)(u + 'a'));

        for (ll v : graph[u])
        {
            degree[v]--;
            if (!degree[v])
                noInDeg.push(v);
        }
    }
}

int main()
{
    fast;

    ll n;
    cin >> n;

    s.resize(n + 1);
    f(1, n + 1, 1) cin >> s[i];

    f(1, n, 1)
    {
        ll len1 = sz(s[i]), len2 = sz(s[i + 1]), flag = 0;

        fo(j, 0, min(len1, len2), 1)
        {
            if (s[i][j] != s[i + 1][j])
            {
                graph[s[i][j] - 'a'].pb(s[i + 1][j] - 'a');
                degree[s[i + 1][j] - 'a']++;
                flag = 1;
                break;
            }
        }
        if (!flag && len1 > len2)
        {
            cout << "Impossible\n";
            return 0;
        }
    }

    topo_sort();
    if (sz(ans) != 26)
        cout << "Impossible\n";
    else
    {
        for (char u : ans)
            cout << u;
    }

    return 0;
}