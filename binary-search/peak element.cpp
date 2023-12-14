#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v, int n)
{

    int st = 0, e = n - 1, ans = 0;

    while (st <= e)
    {
        int mid = st + (e - st) / 2;

        if (mid > 0 && mid < n - 1)
        {

            if (v[mid] > v[mid + 1] && v[mid] > v[mid - 1])
            {
                return v[mid];
            }
            else if (v[mid] < v[mid - 1])
            {
                e = mid - 1;
            }
            else if (v[mid] < v[mid + 1])
            {
                st = mid + 1;
            }
        }

        else if (mid == 0)
        {
            if (v[mid] > v[mid + 1])
                return mid;
            else
                return mid + 1;
        }

        else if (mid == n - 1)
        {
            if (v[mid] > v[mid - 1])
                return mid;
            else
                return mid - 1;
        }
    }
    return -1;
}
int main()
{

    vector<int> v = {1, 3, 4, 5, 12, 7, 6};

    int n = v.size();

    cout << "peak element " << solve(v, n);
}