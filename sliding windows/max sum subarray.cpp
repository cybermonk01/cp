#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxSum(vector<int> &v, int k, int i, int j)
{
    int sum = 0;
    int maxi = INT_MIN;
    while (j < v.size())
    {

        sum += v[i];

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {

            maxi = max(maxi, sum);
            sum -= v[i];
            i++;
            j++;
        }
    }
    return maxi;
}

int main()
{

    vector<int> v = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    int i = 0;
    int j = 0;

    cout << maxSum(v, k, i, j);
}