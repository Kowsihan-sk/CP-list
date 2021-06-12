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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<vl> vll;
#define ff first
#define ss second
#define mp make_pair
typedef pair<ll, ll> pll;

int main()
{
    fast;

    ll n, m, tt = 0;
    vl x = {-1, -1, -1, 0, 0, 1, 1, 1}, y = {-1, 0, 1, -1, 1, -1, 0, 1};
    cin >> n >> m;
    while (n)
    {
        tt++;
        string s;
        s = "";
        vll ar(n + 1, vl(m + 1)), res(n + 1, vl(m + 1)), vis(n + 1, vl(m + 1));
        f(1, n + 1, 1)
        {
            cin >> s;
            fo(j, 1, m + 1, 1)
                ar[i][j] = s[j - 1] - 'A' + 1,
                vis[i][j] = 0, res[i][j] = -1;
        }

        ll lmx = 0, fmx = 0;
        f(1, n + 1, 1)
        {
            fo(j, 1, m + 1, 1)
            {
                lmx = 0;
                if (ar[i][j] == 1)
                {
                    ll a = i, b = j;
                    lmx = vis[i][j] = res[i][j] = 1;
                    queue<pll> q;
                    q.push(mp(a, b));
                    while (!q.empty())
                    {
                        a = q.front().ff, b = q.front().ss;
                        q.pop();
                        fo(k, 0, 8, 1)
                        {
                            ll f = a + x[k], s = b + y[k];
                            if (f > 0 && f <= n && s > 0 && s <= m && vis[f][s] == 0 && (ar[f][s] == (ar[a][b] + 1)))
                            {
                                vis[f][s] = 1;
                                res[f][s] = res[a][b] + 1;
                                if (res[f][s] > lmx)
                                    lmx = res[f][s];
                                q.push(mp(f, s));
                            }
                        }
                    }
                }
                if (lmx > fmx)
                    fmx = lmx;
            }
        }
        cout << "Case " << tt << ": " << fmx << endl;
        cin >> n >> m;
    }

    return 0;
}