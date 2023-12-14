#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b, int) { return a[2] < b[2]; }

void makeSet(vector<int> parent, vector<int> rank, int)
{
}

void findParent(int parent, int node)
{

    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> parent)
{

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {

        parent[v] = u;
        rank[u]++;
    }
}

int kruskal(vector<vector<pii>> graph, int n)
{

    for (int i = 0; i < graph.size(); i++)
    {
        int u = graph[i][0].first;
        int v = graph[i][1].first;
        int wt = graph[i][1].second;
    }

    sort(graph.begin(), graph.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);

    for (int i = 0; i < graph.size(); i++)
    {
        int u = findParent(parent, graph[i][0].first);
        int v = findParent(parent, graph[i][1].second);

        int minWt = 0;
        if (u != v)
        {
            unionSet(u, v, parent);
            minWt += wt;
        }
        return minWt;
    }
}

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
    vector<int> shortest_distances = kruskal(graph, start_vertex, n);

    cout << "Shortest distances from vertex " << start_vertex << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}
