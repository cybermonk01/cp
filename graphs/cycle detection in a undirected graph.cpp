#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

bool isCycle(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;
    queue<int> q;

    parent[node] = -1;
    vis[node] = true;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto nbr : adj[front])
        {
            if (vis[nbr] && parent[nbr] != front)
            {
                return true; // Cycle detected
            }
            else
            {
                if (!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = front;
                }
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges)
{
    int n = edges.size(); // Calculate the number of nodes from the size of edges

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && isCycle(i, vis, adj))
        {
            return "cycle hai";
        }
    }

    return "cycle nahi hai";
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    string result = cycleDetection(edges);

    cout << result << endl;

    return 0;
}
