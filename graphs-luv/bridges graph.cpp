#include <bits/stdc++.h>

using namespace std;

void dfs(int node,int timer,int parent,vector<int>& low,vector<int>& disc, unordered_map<int, bool>&visited, unordered_map<int, list<int>>&adj)
{

    int timer = 0;

    disc[node] = low[node] = timer++;
    visited[node] = true;

    for (auto nbr : adj[node])
    {

        if (nbr == parent)
            continue;
        if (!visited[nbr])
        {

            dfs( nbr, timer, node, low, disc, visited, adj);
//children bhi connected  ho saktea hai back edge wal enbr se to uska bhi uodate hoga so ye karnege

            low[node] = min(low[node], low[nbr]);

            // bridge chek karo

            if (low[nbr] > disc[node])
            {

                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {

            // back edge hai

            low[node] = min(low[node], disc[nbr]);
        }
    }
}

int main()
{

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}, {1, 5}, {5, 6}};

    int n = 6;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(n, -1);
    vector<int> low(n, -1);

    int parent = -1;
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;

    int timer = 0;
    for (int i = 0; i < edges.size(); i++)
    {

        if (!visited[i])
        {

            dfs(i, timer, parent, low, disc, visited, adj);
        }
    }
}