#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int timer, vector<int> &low, vector<int> &disc, vector<int> &ap, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{

    visited[node] = true;

    low[node] = disc[node] = timer++;

    int child = 0;
    for (auto nbr : adj[node])
    {

        if (nbr == parent)
            continue;
        if (!visited[nbr])
        {
            dfs(nbr, node, timer, low, disc, ap, visited, adj);

            // agar ye uss node se attach hai jiske pass back edge hai to isko bhi udate kro

            low[node] = min(low[node], low[nbr]);

            // articulation point bhi check karlo

            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {

            // back esge hai isme
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 3}, {3, 4}, {0, 4}};
    int n = 5;
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int parent = -1;
    int timer = 0;
    vector<int> low(n, 0);
    vector<int> disc(n, 0);
    unordered_map<int, bool> visited;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {

            dfs(i, parent, timer, low, disc, ap, visited, adj);
        }
    }

    cout << "articulation points are " << endl;

    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
            cout << i << " ";
    }
}