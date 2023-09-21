#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> &v)
{

    int m = v.size();
    int n = v[0].size();

    for (int startCol = 0; startCol < n; startCol++)
    {

        if (startCol & 1 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << v[i][startCol] << " ";
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << v[i][startCol] << " ";
            }
        }
    }
}

int main()
{

    vector<vector<int>> v = {
        {2, 4, 5, 6},
        {1, 2, 3, 4},
        {7, 8, 9, 1},
        {4, 5, 6, 7}};

    print(v);
}
