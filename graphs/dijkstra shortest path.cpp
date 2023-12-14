// #include <bits/stdc++.h>
// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
// {
//     // Write your code here.

//     unordered_map < int, list<pair<int, int>> adj;

//     for (int i = 0; i < edges; i++)
//     {

//         int u = vec[i][0];
//         int v = vec[i][1];
//         int w = vec[i][2];

//         adj[u].push_back(make_pair(v, w));
//         adj[v].push_back(make_pair(u, w));
//     }

//     vector<int> dist(vertices);

//     for (int i = 0; i < vertices; i++)
//         dist[i] = INT_MAX;

//     set<pair<int, int>> st;

//     dist[source] = 0;

//     st.insert(make_pair(0, source));

//     while (!st.empty())
//     {

//         auto top = st.begin();

//         int nodeDistance = top.first;
//         int topNode = top.second;

//         st.erase(st.begin());

//         for (auto neighbor : adj[topNode])
//         {
//             if (nodeDistance + neighbor.second < dist[neighbor.first])
//             {
//                 auto record = st.find(make_pair(dist[neighbor.first], neighbor.first));

//                 if (record != st.end())
//                 {
//                     st.erase(record);
//                 }

//                 // distance update

//                 dist[neighbor.first] = nodeDistance + neighbor.second; // second jo hai to adj list wala hai

//                 // push in record

//                 st.insert(make_pair(dist[neighbor.first], neighbor.first));
//             }
//         }
//     }
// }

#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

typedef pair<int, int> pii; // Pair representing (distance, vertex)

vector<int> dijkstra(vector<vector<pii>> &graph, int start)
{

    int n = graph.size();

    vector<int> dist(n, INF);

    dist[start] = 0;

    set<pair<int, int>> st;
    vector<int> ans;
    st.insert({0, start});

    while (!st.empty())
    {
        auto top = st.begin();

        int nodeDist = top->first;
        int topNode = top->second;

        st.erase(st.begin());
        for (auto nbr : graph[topNode])
        {

            if (nodeDist + nbr.second < dist[nbr.first])
            {
                auto existingRecord = st.find({dist[nbr.first], nbr.first});

                if (existingRecord != st.end())
                {
                    st.erase(existingRecord);
                }

                dist[nbr.first] = nodeDist + nbr.second;

                st.insert({dist[nbr.first], nbr.first});
            }
        }
    }
    // for(auto pair: st){
    //     cout<<pair.first << " "<< pair.second;
    //     ans.push_back(pair.first);
    // }cout<<endl;

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