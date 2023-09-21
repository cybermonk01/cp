#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(vector<int> &v, int n, int sum, vector<vector<bool>> &dp)
{

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; i++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {

        for (int j = 1; j < sum + 1; j++)
        {

            if (v[i] <= j)
            {

                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            }
            else if (v[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int equal(vector<int> &v, int n)
{
    int sum = 0;

    for (auto val : v)
    {
        sum += val;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    isSubsetSum(v, n, sum / 2, dp);
}

int main()
{

    vector<int> v = {1, 5, 11, 5};
    int n = v.size();

    equal(v, n);
}