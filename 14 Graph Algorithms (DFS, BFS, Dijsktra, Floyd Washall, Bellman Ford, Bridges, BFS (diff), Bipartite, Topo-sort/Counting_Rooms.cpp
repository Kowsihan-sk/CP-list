/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define f(a, b, c) for (ll i = a; i < b; i += c)
#define sz(n) ((int)(n).size())
typedef vector<ll> vl;
#define fo(i, a, b, c) for (ll i = a; i < b; i += c)
typedef vector<vl> vll;

vll vis;
vector<vector<char>> grid;
vl dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
bool isValid(ll x, ll y)
{
    if (x < 0 || y < 0 || x >= sz(grid) || y >= sz(grid[0]) || vis[x][y] || grid[x][y] == '#')
        return false;
    return true;
}
void dfs(ll x, ll y)
{
    vis[x][y] = 1;
    f(0, 4, 1)
    {
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
    fast;

    ll n, m;
    cin >> n >> m;

    vis.resize(n, vl(m)), grid.resize(n, vector<char>(m));
    f(0, n, 1) fo(j, 0, m, 1) cin >> grid[i][j];
    ll count = 0;
    f(0, n, 1)
    {
        fo(j, 0, m, 1)
        {
            if (vis[i][j] == 0 && (grid[i][j] == '.'))
                dfs(i, j), count++;
        }
    }
    cout << count;

    return 0;
}