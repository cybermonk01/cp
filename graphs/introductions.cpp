#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, int isDirected)
    {

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
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ,";
            }
            cout << endl;
        }
    }

    void DFS(int start, int vertices, vector<bool> &visited)
    {

        visited[start] = true;

        cout << start << endl;

        for (auto nbr : adj[start])
        {
            cout << " par " << start << " -> "
                 << "child" << nbr << endl;
            if (!visited[nbr])
            {

                DFS(nbr, vertices, visited);
            }
        }
    }
};

int main()
{

    int m, n;
    cout << "enter number of nodes" << endl;
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

    vector<bool> visited(n, false);

    g.DFS(0, n, visited);
    g.printGraph();
}