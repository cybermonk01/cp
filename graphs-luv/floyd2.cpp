#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 10;
const int N = 510;

int dist[N][N];
int main()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }

    int m, n;

    cin >> m >> n;

    for (int j = 0; j < m; j++)
    {

        int u, v, wt;

        cin >> u >> v >> wt;
        dist[u][v] = wt;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "I";
            }
            else
                cout << dist[i][j];
        }
    }
}