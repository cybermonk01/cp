#include <bits/stdc++.h>

using namespace std;

vector<int> bellman(int start, int n, int m, vector<pair<int, pair<int, int>>> &adj)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;

    // n-1 baar chalana hai
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = adj[j].first;
            int v = adj[j].second.first;
            int wt = adj[j].second.second;

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}
int main()
{
    int n = 3;
    int m = 3;
    vector<pair<int, pair<int, int>>> adj;

    adj.push_back({1, {2, 2}});
    adj.push_back({2, {3, -1}});
    adj.push_back({1, {3, 2}});
    int start = 1;
    vector<int> dist = bellman(start, n, m, adj);

    for (int i = 0; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}
