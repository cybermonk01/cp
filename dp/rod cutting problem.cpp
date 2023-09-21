#include <iostream>
#include <vector>

using namespace std;

int rodCutting(vector<int> &lengths, vector<int> &prices, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (lengths[i - 1] <= j)
            {
                dp[i][j] = max(prices[i - 1] + dp[i][j - lengths[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}

int main()
{
    vector<int> lengths = {1, 2, 3, 4, 5, 6, 7, 8};    // Possible rod lengths
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20}; // Corresponding prices
    int n = lengths.size();                            // Number of available rod lengths

    int maxLength = 4; // Length of the rod to be cut
    int maxProfit = rodCutting(lengths, prices, maxLength);

    cout << "Maximum profit for rod of length " << maxLength << " is: " << maxProfit << endl;

    return 0;
}
