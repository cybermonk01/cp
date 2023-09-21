#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(vector<int> &v, int i, int j)
{
    int mini = INT_MAX;

    if (i >= j)
        return 0;

    for (int k = i; k <= j - 1; k++)
    {

        int tempAns = solve(v, i, k) + solve(v, k + 1, j) + v[i - 1] * v[k] * v[j];

        mini = min(mini, tempAns);
        // if(tempAns<mini){
        //   mini = tempAns;
        // }
    }
    return mini;
}

int main()
{

    vector<int> v = {40, 20, 30, 10, 30};
    int i = 1;
    int j = v.size() - 1;
    cout << solve(v, i, j);
}
