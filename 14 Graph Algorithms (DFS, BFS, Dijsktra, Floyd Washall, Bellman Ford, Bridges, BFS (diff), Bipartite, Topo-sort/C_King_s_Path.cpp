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
#define all(n) (n).begin(), (n).end()
typedef vector<vl> vll;
#define ff first
#define ss second
#define mp make_pair
typedef pair<ll, ll> pll;

vll offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
map<pll, ll> mp1;
ll srcX, srcY, endX, endY;

bool isValid(ll x, ll y)
{
    if (x < 0 || y < 0 || mp1[{x, y}] != -1)
        return false;
    return true;
}

void bfs(ll x, ll y)
{
    mp1[pll(x, y)] = 0;
    queue<pll> q;
    q.push(mp(x, y));

    while (!q.empty())
    {
        ll currX = q.front().ff, currY = q.front().ss;
        q.pop();

        f(0, 8, 1)
        {
            if (isValid(currX + offset[i][0], currY + offset[i][1]))
            {
                ll newX = currX + offset[i][0], newY = currY + offset[i][1];

                mp1[{newX, newY}] = mp1[{currX, currY}] + 1;
                q.push(mp(newX, newY));
            }
        }
    }
}

int main()
{
    fast;

    ll n, r, a, b;
    cin >> srcX >> srcY >> endX >> endY;
    cin >> n;
    while (n--)
    {
        cin >> r >> a >> b;
        f(a, b + 1, 1) mp1[{r, i}] = -1;
    }
    bfs(srcX, srcY);
    cout << mp1[{endX, endY}] << endl;

    return 0;
}