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

vector<vector<char>> grid;
vll vis, offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
map<pll, char> moves = {{{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{1, 0}, 'D'}, {{0, -1}, 'L'}};
vector<vector<pll>> path;
ll srcX, srcY, endX, endY;

bool isValid(ll x, ll y)
{
    if (x < 0 || y < 0 || x >= sz(grid) || y >= sz(grid[0]) || vis[x][y])
        return false;
    return true;
}

void bfs(ll x, ll y)
{
    queue<pll> q;
    q.push(mp(x, y));
    vis[x][y] = 1;

    while (!q.empty())
    {
        ll currX = q.front().ff, currY = q.front().ss;
        q.pop();

        f(0, 4, 1)
        {
            if (isValid(currX + offset[i][0], currY + offset[i][1]))
            {
                ll newX = currX + offset[i][0], newY = currY + offset[i][1];

                path[newX][newY] = {offset[i][0], offset[i][1]};
                vis[newX][newY] = 1;
                q.push(mp(newX, newY));
            }
        }
    }
}

int main()
{
    fast;

    ll n, m;
    cin >> n >> m;
    grid.resize(n, vector<char>(m)), vis.resize(n, vl(m));
    path.resize(n, vector<pll>(m, {-1, -1}));
    f(0, n, 1) fo(j, 0, m, 1)
    {
        cin >> grid[i][j];
        if (grid[i][j] == '#')
            vis[i][j] = 1;
        if (grid[i][j] == 'A')
            srcX = i, srcY = j;
        if (grid[i][j] == 'B')
            endX = i, endY = j;
    }
    bfs(srcX, srcY);

    if (!vis[endX][endY])
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    vector<pll> ans;
    pll end = {endX, endY};

    while (end.ff != srcX || end.ss != srcY)
    {
        ans.pb(path[end.ff][end.ss]);
        end.ff -= ans.back().ff, end.ss -= ans.back().ss;
    }

    reverse(all(ans));
    cout << sz(ans) << endl;
    f(0, sz(ans), 1)
    {
        cout << moves[{ans[i].ff, ans[i].ss}];
    }
    cout << endl;

    return 0;
}