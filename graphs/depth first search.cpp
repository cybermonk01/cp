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

    bool isCyclic()
    {

        unordered_map<int, bool> visited;
        queue<pair<int, int>> q;

        for (auto &pair : adjList)
        {
            visited[pair.first] = true;
        }

        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                q.push({i, -1});
                visited[i] = true;

                while (!q.empty())
                {

                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for (int neighbour : adjList[node])
                    {
                        if (!visited[neighbour])
                        {
                            visited[neighbour] = true;
                            q.push({neighbour, node});
                        }
                        else if (parent != neighbour)
                            return true;
                    }
                }
            }
        }

        return false;
    }

    bool isCyclicDFSUtil(int start, unordered_map<int, bool> &visited, int parent)
    {

        visited[start] = true;
        for (auto neighbor : adjList[start])
        {

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                if (isCyclicDFS())
                    return true;
                else if (parent != neighbor)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS()
    {
        unordered_map<int, bool> visited;

        for (auto &pair : adjList)
        {
            visited[pair.first];
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && isCyclicDFSUtil(i, visited, -1))
                return true;
        }
        return false;
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