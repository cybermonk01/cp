#include <bits/stdc++.h>

using namespace std;

int static dp[1001][1001];

int solve(string s1, string s2, int m, int n)
{

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {

            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{

    memset(dp, -1, sizeof(dp));
    string s1 = "abcdaf";
    string s2 = "abdgjkf";

    int m = s1.length();
    int n = s2.length();

    cout << solve(s1, s2, m, n);
}