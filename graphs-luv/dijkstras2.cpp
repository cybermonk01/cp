#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(int start, unordered_map<int, list<pair<int, int>>> &adj)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    set<pii> st;
    st.insert({0, start});

    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;
        st.erase(st.begin()); // Remove the processed node from the set

        for (auto nbr : adj[topNode])
        {
            int neighbor = nbr.first;
            int weight = nbr.second;

            if (nodeDist + weight < dist[neighbor])
            {
                st.erase({dist[neighbor], neighbor});
                dist[neighbor] = nodeDist + weight;
                st.insert({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main()
{
    vector<pair<int, pair<int, int>>> edges = {
        {1, {0, 1}}, // Edge from node 0 to node 1 with weight 1
        {2, {0, 2}}, // Edge from node 0 to node 2 with weight 2
        {3, {1, 2}}  // Edge from node 1 to node 2 with weight 3
    };

    unordered_map<int, list<pair<int, int>>> adj;
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Add this line for undirected graph
    }

    vector<int> distances = dijkstra(0, adj);

    for (int i = 0; i < distances.size(); i++)
    {
        cout << "Distance from node 0 to node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
