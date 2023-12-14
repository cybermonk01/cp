#include <bits/stdc++.h>

using namespace std;

int static dp[1001][1001];

int solve(string s1, string s2, int m, int n)
{

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (dp[m][n] != -1)
        return dp[m][n];

    if (s1[m - 1] == s2[n - 1])
    {

        return dp[m][n] = 1 + solve(s1, s2, m - 1, n - 1);
    }
    else
    {

        return dp[m][n] = max(solve(s1, s2, m, n - 1), solve(s1, s2, m - 1, n));
    }

    return dp[m][n];
}

int main()
{

    memset(dp, -1, sizeof(dp));
    string s1 = "abcdaf";
    string s2 = "abcdef";

    int m = s1.length();
    int n = s2.length();

    cout << solve(s1, s2, m, n);
}