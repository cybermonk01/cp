#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {

        pair<int, int> p = make_pair(v, weight);

        adj[u].push_back(p);
    }

    void printGraph(unordered_map<int, list<pair<int, int>>> &adj)
    {

        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {

                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> topo)
    {

        visited[node] = true;

        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, visited, topo);
            }
        }
        topo.push(node);
    }


    void shortestPathDag(){
        
    }
};

int main()
{

    Graph g;

    g.printGraph();

    int n = 6;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(node, visited, s);
        }
    }


    int src = 1;
    vector<int> dist(n);

    for(int i = 0; i< n; i++){
        dist[i]= INT_MAX;
    }

    g.shortestPathDag(src, dist, topo);

}