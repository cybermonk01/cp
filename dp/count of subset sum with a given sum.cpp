#include <iostream>
#include <vector>

using namespace std;
int subsetSum(vector<int> &v, int n, int sum, vector<vector<int>> &dp)
{
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

            if (v[i - 1] <= j)
            {

                dp[i][j] = dp[i - 1][j - v[i - 1]] + dp[i - 1][j];
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

    vector<int> v = {2, 3, 5, 8, 10};
    int sum = 10;
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    subsetSum(v, n, sum, dp);
}
