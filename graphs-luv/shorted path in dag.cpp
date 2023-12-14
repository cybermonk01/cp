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
        for (auto pair : adj)
        {
            cout << pair.first << " -> ";
            for (auto j : pair.second)
            {
                cout << "(" << j.first << " ," << j.second << ")";
            }
            cout << endl;
        }
    }

    void dfs(int node, vector<bool> &visited, stack<int> &st)
    {
        visited[node] = true;
        for (auto nbr : adj[node])
        {
            if (!visited[nbr.first])
            {
                dfs(nbr.first, visited, st);
            }
        }
        st.push(node);
    }

    void getShortestPath(int node, vector<int> &dist, stack<int> &st)
    {
        dist[node] = 0;
        while (!st.empty())
        {
            auto top = st.top();
            st.pop();
            if (dist[top] != INT_MAX)
            {
                for (auto nbr : adj[top])
                {
                    if (dist[nbr.first] > nbr.second + dist[top])
                    {
                        dist[nbr.first] = dist[top] + nbr.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printGraph();

    int n = 6;

    stack<int> st;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, st);
        }
    }

    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    for (auto val : ans)
    {
        cout << val << " ";
    }

    vector<int> dist(n, INT_MAX);

    g.getShortestPath(1, dist, st);

    cout << "*****************************" << endl;
    for (auto val : dist)
    {
        cout << val << " ";
    }
}
