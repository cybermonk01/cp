#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n, int ele)
{

    // solve the infinitely sorted modification and find the end pointer

    int st = 0;
    int e = 1, res = 0;

    while (v[e] < ele)
    {
        st = e;
        e = e * 2;
    }

    // pehla nikalna hai to first occ wala nikalo

    while (st <= e)
    {
        int mid = (st) + (e - st) / 2;

        if (v[mid] == ele)
        {
            res = mid;
            e = mid - 1;
        }
        else if (v[mid] < ele)
        {
            st = mid + 1;
        }
        else if (v[mid] > ele)
        {
            e = mid - 1;
        }
    }
    return res;
}

int main()
{

    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int n = v.size();

    cout << solve(v, n, 1);
}