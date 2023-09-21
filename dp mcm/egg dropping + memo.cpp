#include <bits/stdc++.h>

using namespace std;

int dp[51][101];

int solve(int e, int f)
{

    if (f == 1 || f == 0)
        return f;

    if (e == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int mini = INT_MAX;
    for (int i = 1; i <= f; i++)
    {

        if (dp[e - 1][k - 1] != -1)
        {
            return dp[e - 1][k - 1];
        }
        else
        {
            int low = solve(e - 1, k - 1);
            return dp[e - 1][k - 1] = low;
        }

        if (dp[e][f - k] != -1)
        {
            return dp[e][f - k];
        }
        else
        {
            int high = solve(e, f - k);
            return dp[e][f - k] = high;
        }

        int tempAns = 1 + max(low, high);

        mini = min(mini, tempAns);
    }
    return mini;
}

int main()
{

    int e = 3;
    int f = 5;

    memset(dp, -1, sizeof(dp));
    solve(e, f);
}