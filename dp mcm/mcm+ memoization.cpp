#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solve(vector<int>&v, int i , int j, vector<vector<int>>&dp){



if(i>=j) return 0;

if(dp[i][j] != -1) return dp[i][j];

int mini = INT_MAX;
for(int k = i; k<=j-1;k++ ){

    int temp = solve(v, i, k, dp) + solve(v, k+1, j, dp)+v[i-1]*v[k]*v[j];

    mini = min(mini, temp);

}

return dp[i][j] = mini;



}


int main()
{

    vector<int> v = {40, 20, 30, 10, 30};
    int i = 1;
    int j = v.size() - 1;

    vector<vector<int>> dp(v.size(), vector<int>(v.size(), -1));

    cout << solve(v, i, j, dp);
}
