#include <bits/stdc++.h>

using namespace std;

const int N = 5e2;

int main()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    // deletion order nikalo
    vector<int> del_order(n);
    for (int i = 0; i < n; i++)
        cin >> del_order(i);

    // ulta kro
    reverse(del_order.begin(), del_order.end());
    vector<long long> ans;

    // fir sum nikalo
    for (int k = 0; k < n; k++)
    {
        int k_v = del_order(k);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long newDist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], newDist);
            }
        }
        long long sum = 0;
        for (int i = 0; i <= k; i++ {
                 for (int j = 0; j <= k; j++)
                 {
                     sum += dist[del_order[i]][del_order[j]];
                 }
             } ans.push_back(sum);)
            reverse(ans.begin(), ans.end());
    }
}