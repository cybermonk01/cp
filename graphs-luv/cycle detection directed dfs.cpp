#include <bits/stdc++.h>
using namespace std;

bool cycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto nbr : adj[node])
    {

        if (!visited[node])
        {
            bool isCycle = cycle(nbr, visited, dfsVisited, adj);
            if (isCycle)
                return true;
        }
        else if (visited[node] && dfsVisited[node])
        {
            return true;
        }
    }

    // nikalte hue node ko wapas false karte chalenge
    dfsVisited[node] = false;
    return false;
}

int main()
{

    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 7}, {3, 4}, {4, 7}, {2, 5}, {5, 6}, {6, 8}, {8, 5}};

    unordered_map<int, list<int>> adj;
    int n = 8;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;

    unordered_map<int, bool> dfsVisited;
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans = cycle(i, visited, dfsVisited, adj);
        }
    }

    if (ans)
        cout << "cycle hai";
    else
        cout << "nahi hai";
}