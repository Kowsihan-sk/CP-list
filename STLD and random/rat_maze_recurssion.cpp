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
typedef vector<ll> vl;
typedef vector<vl> vll;

ll rat_move(ll i, ll j, vector<vector<bool>> visited, vll grid, ll n)
{
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] || visited[i][j])
        return 0;
    if (i == n - 1 and j == n - 1)
        return 1;

    visited[i][j] = true;

    ll up, down, left, right;
    up = down = left = right = 0;
    up = rat_move(i - 1, j, visited, grid, n);
    down = rat_move(i + 1, j, visited, grid, n);
    left = rat_move(i, j - 1, visited, grid, n);
    right = rat_move(i, j + 1, visited, grid, n);

    return up + down + left + right;
}

void rat_maze_ques()
{
    ll n;
    cin >> n;

    vll grid(n, vl(n));
    f(0, n, 1) fo(j, 0, n, 1) cin >> grid[i][j];
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    cout << rat_move(0, 0, visited, grid, n) << endl;
}

void rat_move_ritm(ll i, ll j, char move, vector<char> path, vector<vector<bool>> visited, vll grid, ll n)
{
    path.push_back(move);
    if (i < 0 || j < 0 || i >= n || j >= n || !grid[i][j] || visited[i][j])
        return;
    if (i == n - 1 and j == n - 1)
    {
        f(1, path.size(), 1) cout << path[i];
        cout << " ";
        return;
    }
    visited[i][j] = true;

    rat_move_ritm(i - 1, j, 'U', path, visited, grid, n);
    rat_move_ritm(i + 1, j, 'D', path, visited, grid, n);
    rat_move_ritm(i, j - 1, 'L', path, visited, grid, n);
    rat_move_ritm(i, j + 1, 'R', path, visited, grid, n);
}
void rat_in_the_maze_ques()
{
    ll tt;
    cin >> tt;
    while (tt--)
    {
        ll n;
        cin >> n;
        vll grid(n, vl(n));
        ll t = 0;
        f(0, n, 1)
        {
            cin >> grid[t][i];
            if (i == n - 1)
                t++, i = -1;
            if (t == n)
                break;
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<char> path;
        rat_move_ritm(0, 0, 'X', path, visited, grid, n);
        cout << "\n";
    }
}
int main()
{
    fast;
    rat_maze_ques();
    rat_in_the_maze_ques();

    return 0;
}

