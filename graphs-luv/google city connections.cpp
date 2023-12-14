#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;

int parent[N];
int ranki[N];

void make(int v)
{
    parent[v] = v;
    ranki[v] = 0;
}

int findParent(int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionSet(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (u != v)
    {
        if (ranki[u] < ranki[v])
            swap(u, v);

        parent[v] = u;
        ranki[u]++;

        if (ranki[u] == ranki[v])
        {
            ranki[u]++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<pair<int, int>> cities(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<int> c(n + 1), k(n + 1);

    for (int i = 1; i <= n; i++)
    {
        c[i] = i;
        k[i] = i;
    }

    vector<pair<long long, pair<int, int>>> edges;

    for (int i = 1; i <= n; i++)
    {
        edges.push_back({c[i], {0, i}});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            long long cost = dist * 1LL * (k[i] + k[j]);

            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++)
        make(i);
    long long totalCost = 0;
    vector<int> powerStations;
    vector<pair<int, int>> connections;

    for (auto &edge : edges)
    {
        long long cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (findParent(u) == findParent(v))
            continue;

        unionSet(u, v);
        totalCost += cost;

        if (u == 0 || v == 0)
        {
            // Handle power stations differently
            if (u == 0)
                powerStations.push_back(v);
            else
                powerStations.push_back(u);
        }
        else
        {
            connections.push_back({u, v});
        }
    }

    cout << "Total cost " << totalCost << endl;
    cout << "Number of power stations " << powerStations.size() << endl;
    for (auto station : powerStations)
    {
        cout << station << " ";
    }
    cout << endl;

    cout << "Number of connections " << connections.size() << endl;
    for (auto connection : connections)
    {
        cout << "(" << connection.first << "," << connection.second << ")" << endl;
    }
}
