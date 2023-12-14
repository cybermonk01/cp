#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// vector<int>compMembers;
vector<vector<int>> components;

vector<int> dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    cout << node << " ";
    vector<int> compMembers;

    vis[node] = true;
    compMembers.push_back(node);
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, adj);
        }
    }
    return compMembers;
}

int countComp(vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    int n = edges.size();
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> vis;
    int count = 0;

    for (auto node_pair : adj)
    {
        int node = node_pair.first;
        if (!vis[node])
        {

            components.push_back(dfs(node, vis, adj));
            count++;
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {5, 6}, {8, 9}};

    cout << countComp(edges);

    for (auto i : components)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
