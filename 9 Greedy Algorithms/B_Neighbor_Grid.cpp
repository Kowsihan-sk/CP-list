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
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
#define fd(a, b, c) for (ll i = a; i >= b; i -= c)
#define fdo(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
typedef vector<ll> vl;
typedef vector<vl> vll;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
const int N = (int)2 * 1e5 + 10;

bool check_true(vll ar, ll x, ll y)
{
    ll n = ar.size(), m = ar[0].size(), count = 0, pts = ar[x][y];
    if (x > 0)
        count += ar[x - 1][y];
    if (x != (n - 1))
        count += ar[x + 1][y];
    if (y > 0)
        count += ar[x][y - 1];
    if (y != (m - 1))
        count += ar[x][y + 1];

    if (count == pts)
        return true;
    return false;
}

int main()
{
    fast;
    ll TT;
    cin >> TT;

    while (TT--)
    {
        ll n, m;
        cin >> n >> m;
        vll ar(n, vl(m));
        f(0, n, 1) fo(j, 0, m, 1) cin >> ar[i][j];

        bool flag = false;
        f(0, n, 1)
        {
            fo(j, 0, m, 1)
            {
                ll pts = 0;
                if (i > 0)
                    pts++;
                if (i < (n - 1))
                    pts++;
                if (j > 0)
                    pts++;
                if (j < (m - 1))
                    pts++;
                if (ar[i][j] > pts)
                {
                    cout << "NO\n", flag = true;
                    break;
                }
                ar[i][j] = pts;
            }
            if (flag)
                break;
        }
        if (!flag)
        {
            cout << "YES\n";
            f(0, n, 1)
            {
                fo(j, 0, m, 1) cout << ar[i][j] << " ";
                cout << endl;
            }
        }
    }

    return 0;
}