#include <bits/stdc++.h>

using namespace std;

class graph
{

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool isDirected)
    {
        // isDiredcted == 1 -> directed

        adj[u].push_back(v);

        if (isDirected == 0)
        {

            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }

    void BFS(int start, int vertices)
    {
        queue<int> q;

        vector<bool> visited(vertices, false); // Initialize with the correct size

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            for (auto neighbour : adj[curr])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);

                    visited[neighbour] = true;
                }
            }
        }
    }

    void DFS(int start, int vertices)
    {
        vector<bool> visited(vertices, false); // Initialize with the correct size

        visited[start] = true;

        cout << start << " ";

        for (auto neighbor : adj[start])
        {
            if (!visited[neighbor])
            {
                DFS(neighbor, vertices); // Call DFS recursively with the neighbor
            }
        }
    }
};

int main()
{

    int m, n;
    cout << "enter the number of nodes" << endl;
    cin >> n;

    cout << "enter number of edges" << endl;
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printGraph();

    cout << endl
         << "BFS traversal starting from node 2:" << endl;
    g.BFS(2, 4);
    cout << endl
         << "dFS traversal starting from node 2:" << endl;
    g.BFS(2);
}