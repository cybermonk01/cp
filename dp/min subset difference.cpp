// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// int subsetSum(vector<int> &v, int n, int sum, vector<vector<int>> &dp)
// {

//     for (int i = 0; i < n + 1; i++)
//     {
//         for (int j = 0; j < sum + 1; j++)
//         {
//             if (i == 0)
//                 dp[i][j] = 0;
//             if (j == v[0])
//                 dp[i][j] = 1;
//         }
//     }

//     for (int i = 1; i < n + 1; i++)
//     {
//         for (int j = 1; j < sum + 1; j++)
//         {

//             if (v[i - 1] <= j)
//             {
//                 dp[i][j] = dp[i - 1][j - v[i - 1]] + dp[i - 1][j];
//             }
//             else if (v[i - 1] > j)
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     int minDiff = INT_MAX;

//     for (int j = sum / 2; j >= 0; j--)
//     {
//         int currentDiff = sum - 2 * dp[n][j];
//         minDiff = min(minDiff, currentDiff);
//     }

//     return minDiff;
// }

// int minsubDiff(vector<int> &v, int n)
// {
//     int sum = 0;
//     for (auto val : v)
//     {
//         sum += val;
//     }

//     vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
//     return subsetSum(v, n, sum, dp);
// }

// int main()
// {
//     vector<int> v = {5, 1, 5, 10};
//     int n = v.size();
//     cout << minsubDiff(v, n);
// }

// practice 2

#include <bits/stdc++.h>

using namespace std;

int subsetSum(vector<int> &v, int n, int &sum)
{
    int dp[n + 1][sum + 1];

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

                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int minDiff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n][j])
        {
            int currDiff = sum - 2 * j;
            minDiff = min(minDiff, currDiff);
        }
    }
    return minDiff;
}

int minsubDiff(vector<int> &v, int n)
{
    int sum = 0;
    for (auto val : v)
    {
        sum += val;
    }

    return subsetSum(v, n, sum);
}

int main()
{
    vector<int> v = {5, 3, 5, 10};
    int n = v.size();
    // memset(dp, -1, sizeof(dp));
    cout << minsubDiff(v, n);
}
