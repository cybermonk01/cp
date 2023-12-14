#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int cap, int n, int dp[][1001])
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
        {

            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {

            if (wt[i - 1] <= j)
            {

                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else if (wt[i - 1] > j)
            {

                dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[i][j];
    }
}
int main()
{

    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int cap = 50;
    int n = wt.size();
    int dp[n + 1][1001];
    memset(dp, -1, sizeof(dp));
    cout << knapsack(wt, val, cap, n, dp);
}
