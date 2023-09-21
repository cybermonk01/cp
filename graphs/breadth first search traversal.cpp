#include <bits/stdc++.h>

using namespace std;

class graph()
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
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
    void BFS(int start)
    {
        // queue me daalo
        // visited mark kro
        // ans me daalo

        // fir neighbour check kro
        // ki visited na nikle
        // then queue me daalo
        // aur visited mark kr

        unordered_map<int, bool> visited;
        queue<int> q;

        for (auto &pair : adj)
        {
            visited[pair.first] = false;
        }

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {

            int current = q.front();
            ans.push_back(current);
            cout << current << " ";
            q.pop();

            for (int neighbout : adj[current])
            {
                if (!visited[neighbout])
                {
                    q.push(neighbout);
                    visited[neighbout] = true;
                }
            }
        }
    }

    void DFS(int start, unordered_map<int, bool> &visited)
    {

        queue<int> q;

        q.push(start);

        visited[start] = true;

        for (auto neighbor : adj[start])
        {
            if (!visited[neighbor])
            {
                DFS(neighbor, visited);
            }
        }
    }
};

int main()
{

    int m, n;

    cout << "enter number of nodes" << endl;
    cin >> m;

    cout << "enter number of edges" << endl;
    cin >> n;

    graph g;

    for (int i = 0; i < m; i++)
    {

        int u, v;

        cin >> u >> v;

        g.addEdge(u, v, 0);
    }
    g.printGraph();
}