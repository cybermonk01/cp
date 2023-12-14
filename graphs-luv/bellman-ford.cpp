#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 10;

void bellman(vector<vector<pair<int, int>>> &edges, int n, int start)
{
    vector<int> dist(n, INF);
    dist[start] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int wt = edges[j][0];
            int u = edges[j][1].first;
            int v = edges[j][1].second;

            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    int flag = 0;
    for (int j = 0; j < edges.size(); j++)
    {
        int wt = edges[j][0];
        int u = edges[j][1].first;
        int v = edges[j][1].second;

        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            flag = 1;
        }
    }

    if (flag == 1)
        cout << "Negative weighted hai";
    else
        cout << "Nahi hai";
}

int main()
{
    int n = 3;     // Adjust the number of nodes as needed
    int start = 0; // Choose your starting node

    // Define the edges in the format {weight, {from, to}}
    vector<vector<pair<int, int>>> edges = {
        {1, {0, 1}},
        {2, {0, 2}},
        {3, {1, 2}},
        {4, {2, 1}} // Add reverse edges for undirected graph
    };

    bellman(edges, n, start);

    return 0;
}
