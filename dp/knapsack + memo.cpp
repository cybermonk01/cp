#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int cap, int n, int dp[][1001])
{
    if (n == 0 || cap == 0)
    {
        return 0;
    }

    if (dp[n + 1][cap + 1] != -1)
        return dp[n + 1][cap + 1];

    if (wt[n - 1] <= cap)
    {
        return dp[n + 1][cap + 1] = max(val[n - 1] + knapsack(wt, val, cap - wt[n - 1], n - 1), knapsack(wt, val, cap, n - 1));
    }
    else
    {
        return dp[n + 1][cap + 1] = knapsack(wt, val, cap, n - 1);
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