#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &coins, int n, int sum)
{

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {

            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{

    vector<int> coins = {1, 2, 3, 4, 5};
    int n = coins.size();
    int sum = 5;

    cout << solve(coins, n, sum);
}

// practice 2

#include <bits/stdc++.h>

using namespace std;

int maxCoins(vector<int> &v, int n, int sum)
{

    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {

            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - v[i - 1]] + dp[i - 1][j]; // unbounded
            }
            else if (v[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{

    vector<int> v = {1, 2, 3};
    int n = v.size();
    int sum = 5;

    maxCoins(v, n, sum);
}