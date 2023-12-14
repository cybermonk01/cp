#include <bits/stdc++.h>

using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj)
{

    visited[node] = true;

    for (auto nbr : adj[node])
    {
        if (!visited[nbr])

            topoSort(nbr, visited, st, adj);
    }

    st.push(node);
}

int main()
{

    vector<vector<int>> edges = {{1, 2}, {2, 4}, {1, 3}, {3, 4}, {4, 5}};

    int n = 5;
    vector<bool> visited(n, false);
    stack<int> st;
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    for (int i = 1; i < n; i++)
    {

        if (!visited[i])
        {
            topoSort(i, visited, st, adj);
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
}