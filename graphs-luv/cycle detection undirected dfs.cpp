#include <bits/stdc++.h>

using namespace std;

bool dfsCycle(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{

    visited[node] = true;

    for (auto nbr : adj[node])
    {

        if (!visited[nbr])
        {
            bool cycle = dfsCycle(nbr, node, visited, adj);
            if (cycle)
            {
                return true;
            }
        }
        else if (visited[nbr] && parent != node)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {5, 7}, {6, 8}, {7, 8}, {8, 9}};

    int n = 9;

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // har component ke liye

    unordered_map<int, bool> visited;
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {

        if (!visited[i])
        {

            ans = dfsCycle(i, -1, visited, adj);
            if (ans)
            {
                break; // If a cycle is detected, there is no need to continue checking other components
            }
        }
    }

    if (ans)
        cout << "cycle hai";
    else
        cout << "nahi hai";
}