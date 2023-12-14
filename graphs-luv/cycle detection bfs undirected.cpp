#include <bits/stdc++.h>

using namespace std;

bool isCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{

    unordered_map<int, int> parent;

    parent[node] = -1;
    visited[node] = true;

    queue<int> q;
    q.push(node);

    while (!q.empty())
    {

        int front = q.front();
        q.pop();

        for (auto nbr : adj[front])
        {

            if (visited[nbr] == true && parent[nbr] != front)
            {
                return true;
            }
            else
            {
                q.push(nbr);
                parent[nbr] = front;
                visited[nbr] = true;
            }
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {6, 8}, {5, 7}, {7, 8}, {8, 9}};

    int n = 9;
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = false;
    for (int i = 0; i < n; i++)
    {

        ans = isCycle(i, visited, adj);
        if (ans)
            break;
    }
    if (ans == true)
    {
        cout << "cycle hai";
    }
    else
        cout << "nhi hai";
}