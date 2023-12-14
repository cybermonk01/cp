#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &v, int m, int n, int key)
{
    int i = 0, j = m - 1;

    while (i >= 0 && i < n && j >= 0 && j < m)
    {

        if (v[i][j] == key)
        { // iaur  j alag alag bhejna hai
            return i + j;
        }
        else if (v[i][j] < key)
        {
            i++;
        }
        else if (v[i][j] > key)
        {
            j--;
        }
    }
    return -1;
}

int main()
{

    vector<vector<int>> v = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 54}};

    int m = 4, n = 4;

    cout << solve(v, m, n, 29);
}