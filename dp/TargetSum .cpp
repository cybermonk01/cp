#include <iostream>
#include <vector>

using namespace std;

int isSubsetSum(vector<int> &v, int n, int s, vector<vector<int>> &dp)
{

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < s + 1; j++)
        {

            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < s + 1; j++)
        {

            if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - v[n - 1]] + dp[i - 1][j];
            }
            else if (v[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}

int subsets(vector<int> &v, int n, int diff)
{

    int total = 0;

    for (auto val : v)
    {

        total += val;
    }

    int sub = (total + diff) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(sub + 1, 0));
    isSubsetSum(v, n, sub, dp);
}

int main()
{

    vector<int> v = {1, 1, 2, 3};
    int diff = 1;

    int n = v.size();

    subsets(v, n, diff);
}