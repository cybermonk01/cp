#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solve(vector<int> &coins, int n, int sum)
{

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));
    for (int i = 0; i < n + 1; i++)
    {

        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0)
                dp[i][j] = 0;
        }
    }

    for (int j = 1; j < sum + 1; j++)
    {
        if (j % coins[0] == 0)
            dp[1][j] = j / coins[0];
        else
            dp[1][j] = INT_MAX - 1;
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    vector<int> coins = {3, 2, 4};
    int n = coins.size();
    int sum = 10;

    cout << solve(coins, n, sum);
}