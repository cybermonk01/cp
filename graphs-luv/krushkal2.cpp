#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt)
    {

        pair<int, int> p = make_pair(v, wt);

        adj[u].push_back(p);
    }

    void printGraph()
    {

        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {

                cout << "(" << j.first << " ," << j.second << ")";
            }
            cout << endl;
        }
    }

    void makeSet(vector<int> &parent, vector<int> &rank, int n)
    {

        for (int i = 0; i < n; i++)
        {

            parent[i] = i;
            rank[i] = 0;
        }
    }

    void findParent(int node, vector<int> &parent)
    {

        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if (rank[u] < rank[v])
        {
            swap(u, v);
        }
        parent[u] = v;
        rank[u]++;
    }

    void krushkal(int m)
    {
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < m; i++)

        {
            int u, v, wt;
            cin >> u >> v >> wt;
            edges.push_back({wt, {u, v}});
        }

        sort(edges.begin(), edges.end());

        int totalWt = 0;
        for (auto &edge : edges)
        {
            int wt = edges.first;
            int u = edges.second.first;
            int v = edges.second.second;

            if (findParent(u) == findParent(v))
                continue;
            unionSet(u, v);
            totalWt += wt;
            cout << u << " " << v << endl;
        }
        cout << totalWt;
    }
};

int main()
{

    Graph g;

    // g.addEdge(0, 1, 5);
    // g.addEdge(0, 2, 3);
    // g.addEdge(1, 2, 2);
    // g.addEdge(1, 3, 6);
    // g.addEdge(2, 3, 7);
    // g.addEdge(2, 4, 4);
    // g.addEdge(2, 5, 2);
    // g.addEdge(3, 4, 11);
    // g.addEdge(4, 5, 12);

    int n = 6, m = 9;
    g.krushkal(m);
    g.printGraph();
}