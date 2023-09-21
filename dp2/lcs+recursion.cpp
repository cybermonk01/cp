#include <iostream>
#include <string>
#include <cstring>

using namespace std;
static int dp[1001][1001];
int lcs(string &s1, string &s2, int m, int n)
{

    if (n == 0 || m == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];

    if (s1[m - 1] == s2[n - 1])
    {
        return dp[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
    }
    else
    {

        return dp[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
}

int main()
{

    string s1 = "abbcdefg";
    string s2 = "abacfr";

    int m = s1.length();
    int n = s2.length();
    memset(dp, -1, sizeof(dp));

    cout << lcs(s1, s2, m, n);
}
