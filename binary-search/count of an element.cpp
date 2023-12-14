#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &v, int n, int ele)
{

    int low = 0;
    int high = n - 1;
    int res = 0;
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] == ele)
        {
            // return mid;

            // agar first occ nikalna ho to
            res = mid;
            high = mid - 1;
        }
        else if (v[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int lastOcc(vector<int> &v, int n, int ele)
{

    int st = 0, e = n - 1, res = 0;
    while (st < e)
    {

        int mid = st + (e - st) / 2;

        if (v[mid] == ele)
        {

            res = mid;
            st = mid + 1;
        }
        else if (v[mid] < ele)
        {
            st = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
}

int main()
{

    vector<int> v = {1, 5, 7, 7, 7, 8, 9};
    int n = v.size();
    int ele = 7;

    int first = firstOcc(v, n, ele);

    int last = lastOcc(v, n, ele);

    cout << "count of ele " << ele << " is " << last - first + 1;
}