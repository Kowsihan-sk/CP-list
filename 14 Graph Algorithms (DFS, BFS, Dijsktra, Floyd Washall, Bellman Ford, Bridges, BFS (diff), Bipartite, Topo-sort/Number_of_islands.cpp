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
vl dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
bool isValid(ll x, ll y, vector<vector<char>> grid)
{
    if (x < 0 || y < 0 || x >= sz(grid) || y >= sz(grid[0]) || vis[x][y] || grid[x][y] == '0')
        return false;
    return true;
}
void dfs(ll x, ll y, vector<vector<char>> grid)
{
    vis[x][y] = 1;
    f(0, 4, 1)
    {
        if (isValid(x + dx[i], y + dy[i], grid))
            dfs(x + dx[i], y + dy[i], grid);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    vis.resize(sz(grid), vl(sz(grid[0])));
    ll count = 0;
    f(0, sz(grid), 1)
    {
        fo(j, 0, sz(grid[0]), 1)
        {
            if (vis[i][j] == 0 && (grid[i][j] == '1'))
                dfs(i, j, grid), count++;
        }
    }

    return count;
}

int main()
{
    fast;

    ll n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    f(0, n, 1) fo(j, 0, m, 1) cin >> grid[i][j];
    cout << numIslands(grid);

    return 0;
}