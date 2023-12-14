#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = INT_MAX;

vector<int> dijkstra(vector<vector<pii>> &graph, int start)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    set<pii> st;

    st.insert({0, start});

    while (!st.empty())
    {

        auto top = *(st.begin());

      int  nodeDist = top.first;
        int topNode = top.second;
        st.erase(st.begin());

        for (auto nbr : graph[topNode])
        {

            if (nodeDist + nbr.second < dist[nbr.first])    //dist+wt< dist[first]
            {
                auto record = st.find({dist[nbr.first], nbr.first});

                if (record != st.end())
                {
                    st.erase(record);
                }
            }

            dist[nbr.first] = nodeDist + nbr.second;

            st.insert({dist[nbr.first], nbr.first});
        }
    }

    return dist;
}

int main()
{
    int n = 6; // Number of vertices
    vector<vector<pii>> graph(n);

    // Add edges to the graph (vertex, weight)
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({5, 1});
    graph[4].push_back({3, 2});
    graph[4].push_back({5, 5});

    int start_vertex = 0;
    vector<int> shortest_distances = dijkstra(graph, start_vertex);

    cout << "Shortest distances from vertex " << start_vertex << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}