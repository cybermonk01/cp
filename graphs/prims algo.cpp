#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {

        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[i] = 0;
    parent[i] = -1;

    for (int i = 0; i < n; i++)
    {

        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int w = neighbor.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

// #include <bits/stdc++.h>

// using namespace std;

// typedef pair<int, int> pii;

// vector<int> prims(vector<vector<pii>> &graph, int node, int n)
// {
//     vector<int> keys(n, INT_MAX);
//     vector<bool> mst(n, false);
//     vector<int> parent(n, -1);

//     keys[node] = 0;

//     for (int i = 0; i < n - 1; i++)
//     {
//         int u = -1;
//         for (int v = 0; v < n; v++)
//         {
//             if (!mst[v] && (u == -1 || keys[v] < keys[u]))
//             {
//                 u = v;
//             }
//         }

//         mst[u] = true;

//         for (auto &edge : graph[u])
//         {
//             int v = edge.first;
//             int wt = edge.second;
//             if (!mst[v] && wt < keys[v])
//             {
//                 parent[v] = u;
//                 keys[v] = wt;
//             }
//         }
//     }

//     return keys;
// }

int main()
{
    int n = 6; // Number of vertices
    vector<vector<pii>> graph(n);

    // Add edges to the graph (vertex, weight)
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({0, 2}); // Add reverse edge
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({0, 4}); // Add reverse edge
    graph[2].push_back({1, 1}); // Add reverse edge
    graph[2].push_back({4, 3});
    graph[3].push_back({1, 7}); // Add reverse edge
    graph[3].push_back({5, 1});
    graph[4].push_back({2, 3}); // Add reverse edge
    graph[4].push_back({5, 5});

    int start_vertex = 0;
    vector<int> shortest_distances = prims(graph, start_vertex, n);

    cout << "Shortest distances from vertex " << start_vertex << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}
