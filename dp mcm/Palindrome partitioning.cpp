#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;
int dp[i][j];

int solve(string &s, int i, int j)
{

    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {

        int tempAns = solve(s, i, k) + solve(s, k + 1, j) + 1;

        mini = min(mini, tempAns);
    }

    return dp[i][j] = mini;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s = "nitin";

    int i = 1;
    int j = s.length() - 1;

    solve(s, i, j);
}
