#include <bits/stdc++.h>

using namespace std;

int static dp[1001][1001];

string printLcs(string s1, string s2, int m, int n)
{

    int i = m, j = n;
    string ans;
    while (i > 0 && j > 0)
    {

        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

string solve(string s1, string s2, int m, int n)
{

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {

            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return printLcs(s1, s2, m, n);
}

int main()
{

    memset(dp, -1, sizeof(dp));
    string s1 = "abcdaf";
    string s2 = "abdfghj";

    int m = s1.length();
    int n = s2.length();

    cout << solve(s1, s2, m, n);
}