#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &v, int sum)
{
    int i = 0, j = 0;
    int maxi = 0;
    int total = 0;

    while (j < v.size())
    {

        total += v[j];

        if (total < sum)
        {

            j++;
        }
        else if (total == sum)
        {
            maxi = max(maxi, j - i + 1);
        }
        else if (total > sum)
        {

            while (total > sum)
            {
                total -= v[i];
            }
        }
    }

    return maxi;
}
int main()
{
    vector<int> v = {4, 1, 1, 1, 1, 2, 3, 6, 4};
    int sum = 5;

    solve(v, sum);

    return 0;
}