#include <bits/stdc++.h>

using namespace std;

// modified binary search

int solve(vector<int> &v, int n, int ele)
{

    int st = 0, e = n - 1;

    while (st <= e)
    {

        int mid = (st) + (e - st) / 2;

        if (v[mid] == ele)
        {
            return mid;
        }
        else if (v[mid - 1] == ele && mid - 1 >= st)
        {
            return mid - 1;
        }
        else if (v[mid + 1] == ele && mid + 1 <= e)
        {
            return mid + 1;
        }
        else if (v[mid] < ele)
        {
            st = mid + 2; // mid-1 pehle hi check kar chuke hai
        }
        else if (v[mid] > ele)
        {
            e = mid - 2;
        }
    }
    return -1;
}

int main()
{

    vector<int> v = {10, 30, 20, 50, 40};
    int n = v.size();

    int ele = 20;
    cout << solve(v, n, ele);
}