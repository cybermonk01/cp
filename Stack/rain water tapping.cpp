#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v, int n)
{

    vector<int> mxl(n);
    vector<int> mxr(n);

    int mxl[0] = v[0];
    for (int i = 1; i < n; i++)
    {

        mxl[i] = maxi(mxl[i - 1], v[i]);
    }

    int mxr[n - 1] = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        mxr[i] = maxi(mxr[i + 1], v[i]);
    }

    vector<int> water(n);

    for (int i = 0; i < n; i++)
    {

        water[i] = min(mxr[i], mxl[i]) - v[i];
    }
    int sum = 0;
    for (auto val : water)
    {
        sum += val;
    }
    return sum;
}

int main()
{

    vector<int> v = {3, 0, 0, 2, 0, 4};
    int n = v.size();
    int water = solve(v, n);

    cout << "total water trapped was " << water << endl;
}