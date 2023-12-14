#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v, int n, int ele)
{

    int st = 0, e = 1, res = 0;

    while (v[e] <= ele)
    {
        st = e;
        e = e * 2;
    }

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
        return res;
    }
    return -1;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 8, 9, 11, 12, 14, 15, 16};

    int n = v.size();
    int ele = 4;

    cout << solve(v, n, ele);
}