#include <bits/stdc++.h>

using namespace std;

bool isCycle(int node, int parent, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {

            bool isDetected = isCycle(nbr, node, vis, adj);
            if (isDetected)
            {
                return true;
            }
        }
        else if (vis[nbr] == true && parent[nbr] != node)
        {
            return true; // visited hai aur wo parent bhi nahi hai matlab cycle hai
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges)
{

    int n = edges.size();

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> vis;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {

        if (!vis[i])
        {
            ans = isCycle(i, -1, vis, adj);
        }
    }

    if (ans)
    {
        return "cycle hai";
    }
    else
    {
        return "nahi hai";
    }
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {4, 5}, {5, 6}, {6, 7}, {6, 8}, {7, 5}};
    string result = cycleDetection(edges);

    cout << result << endl;

    return 0;
}