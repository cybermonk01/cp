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

    void dfs(int start, vector<bool> &visited, vector<int> &currentComponentVector)
    {

        if (visited[start])
        {
            return;
        }

        visited[start] = true;
        currentComponentVector.push_back(start);

        for (auto nbr : adj[start])
        {

            if (!visited[nbr])
            {
                dfs(nbr, visited, currentComponentVector);
            }
        }
    }

    void connectedComponents(int vertices)
    {

        vector<bool> visited(vertices, false);
        vector<int> currentComponentVector;

        vector<vector<int>> allComponents;

        int componentCount = 0;
        for (int i = 1; i <= vertices; i++)
        {

            if (visited[i] == false)
            {
                currentComponentVector.clear();
                dfs(i, visited, currentComponentVector);

                allComponents.push_back(currentComponentVector);
                componentCount++;
            }
        }

        cout << "number of components " << componentCount << endl;

        for (auto cc : allComponents)
        {
            for (auto component : cc)
            {
                cout << component << " ,";
            }
            cout << endl;
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

    // g.DFS(0, n, visited);
    g.connectedComponents(n);
    g.printGraph();
}