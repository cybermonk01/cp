#include <bits/stdc++.h>

using namespace std;

class graph
{

public:
    unordered_map<int, list<int>> adj;

    addEdge(int u, int v, bool isDirected)
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
}

int
main()
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
}