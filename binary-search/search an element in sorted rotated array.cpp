#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n)
{

    int st = 0, e = n - 1;

    while (st <= e)
    {
        if (v[st] <= v[e])
        {
            return st;
        }

        int mid = (st) + (e - st) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (v[mid] <= v[prev] && v[mid] <= v[next])
        {

            return mid;
        }
        else if (v[st] < v[mid])
        {
            st = mid + 1;
        }
        else if (v[mid] < v[e])
        {
            e = mid - 1;
        }
    }
    return -1;
}

int binary(vector<int> &v, int n, int st, int e, int ele)
{

    while (st <= e)
    {
        int mid = (st) + (e - st) / 2;

        if (v[mid] == ele)
        {
            return mid;
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
    return -1;
}

int main()
{

    vector<int> v = {11, 12, 14, 15, 1, 2, 4, 5};

    int n = v.size() - 1;
    // find pivot element index then do a binary search in both half to find the target element
    int pivot = solve(v, n);

    int ele = 14;
    int rightAns = binary(v, n, pivot, n, ele);
    int leftAns = binary(v, n, 0, pivot - 1, ele);

    cout << leftAns;
    cout << rightAns;
    cout << rightAns;
}