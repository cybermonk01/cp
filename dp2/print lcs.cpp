#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int printLcs(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
{
    string ans;

    int i = m, j = n;

    while (i != 0 && j != 0)
    {

        if (dp[i - 1] == dp[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1] > dp[j - 1])
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

    cout << ans;
}

int lcs(string &s1, string &s2, int m, int n)
{

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;
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
    return printLcs(s1, s2, m, n, dp);
}

int main()
{

    string s1 = "abbcdef";
    string s2 = "abbcefr";

    int m = s1.length();
    int n = s2.length();

    cout << lcs(s1, s2, m, n);
}
