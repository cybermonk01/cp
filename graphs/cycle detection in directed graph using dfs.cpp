#include <bits/stdc++.h>

using namespace std;

bool isCycle(int node, int parent, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsVis, unordered_map<int, list<int>> adj)
{

    vis[node] = true;
    dfsVis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            vis[nbr] = true;
            dfsVis[nbr] = true;
        }
        else
        {
            if (vis[nbr] == true && parent != node)
            {
                bool detected = isCycle(nbr, node, vis, dfsVis, adj);
                if (detected)
                {
                    return true;
                }
            }
        }
        vis[node] = false;
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
    }

    unordered_map<int, bool> vis;
    unordered_map<int, bool> dfsVis;
    for (int i = 0; i < n; i++)
    {

        if (!vis[i])
        {
            bool ans = isCycle(i, -1, vis, dfsVis, adj);
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
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {3, 8}, {8, 4}, {2, 4}, {4, 5}, {5, 6}, {6, 4}};
    string result = cycleDetection(edges);

    cout << result << endl;

    return 0;
}