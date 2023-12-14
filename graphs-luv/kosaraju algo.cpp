#include <bits/stdc++.h>

using namespace std;
// kosaraju me hum strongly connected components niklate hai
// iske liye pehle topo order nikalna hoga
// uske baad transpose karenge graph ko -make graph me agar a se b aa raha hai to uski direction ulti kar denge b->a

// uske baad revDfs nikalenge aur count badhate jayenge us count se hume no of strongly connected components mil jayenge

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj)
{

    visited[node] = true;

    for (auto nbr : adj[node])
    {

        if (!visited[nbr])
        {
            dfs(nbr, visited, st, adj);
        }
    }

    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{

    visited[node] = true;

    for (auto nbr : transpose[node])
    {

        if (!visited[nbr])
        {
            revDfs(nbr, visited, transpose);
        }
    }
}

int main()
{

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 1}, {2, 4}, {4, 5}};
    int n = 5;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][1];
        int v = edges[i][0];

        adj[u].push_back(v);
    }

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, visited, st, adj);
    }

    // transpose the graph

    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    int count = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            count++;
            revDfs(top, visited, transpose);
        }
    }
    cout << "count of strongly connected components " << count << endl;
}