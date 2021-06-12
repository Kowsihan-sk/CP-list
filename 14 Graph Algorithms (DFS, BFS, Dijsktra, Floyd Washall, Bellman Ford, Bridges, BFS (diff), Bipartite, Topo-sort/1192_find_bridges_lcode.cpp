/** Author : S Kowsihan **/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int p, int timer, vector<vector<int>> &adj, vector<vector<int>> &ans, vector<int> &vis, vector<int> &tin, vector<int> &low)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (int child : adj[node])
    {
        if (child == p)
            continue;
        if (vis[child])
        {
            low[node] = min(low[node], tin[child]);
        }
        else
        {
            dfs(child, node, timer, adj, ans, vis, tin, low);
            low[node] = min(low[node], low[child]);
            if (low[child] > tin[node])
            {
                // IS_BRIDGE(v, to);
                ans.push_back({node, child});
            }
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    int timer = 0;
    vector<int> vis(n), tin(n, -1), low(n, -1);
    vector<vector<int>> adj(n), ans;

    for (vector<int> &vec : connections)
    {
        adj[vec[0]].push_back(vec[1]);
        adj[vec[1]].push_back(vec[0]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
            dfs(i, -1, timer, adj, ans, vis, tin, low);
    }
    return ans;
}

// cp algo
int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                // IS_BRIDGE(v, to);
            }
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    // leet code soln
}
