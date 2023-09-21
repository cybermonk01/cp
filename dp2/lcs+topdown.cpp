#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
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
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else if (s1[i - 1] != s2[j - 1])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}
int main()
{

    string s1 = "abbcdefg";
    string s2 = "abacfr";

    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    cout << lcs(s1, s2, m, n, dp);
}
