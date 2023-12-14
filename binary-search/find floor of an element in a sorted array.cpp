#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v, int n, int ele)
{

    int st = 0, e = n - 1, res = 0;

    while (st <= e)
    {

        int mid = st + (e - st) / 2;

        if (v[mid] == ele)
        {
            return mid;
        }
        else if (v[mid] < ele)
        {
            florr = v[mid];
            cout << "florr " << florr << endl;
            st = mid + 1;
        }
        else if (v[mid] > ele)
        {
            ciell = v[mid];
            cout << "ceill " << ceill << endl;
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 6, 7, 8};
    int n = v.size();
    int ele = 5;
    cout << solve(v, n, ele);
}