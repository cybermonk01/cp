#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n)
{
    int st = 0, e = n - 1;

    while (st <= e)
    {
        if (v[st] <= v[e])
        {
            return v[st]; // Entire array is sorted, so return the minimum element
        }

        int mid = st + (e - st) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if (v[mid] <= v[prev] && v[mid] <= v[next])
        {
            return v[mid]; // Minimum element found
        }
        else if (v[st] < v[mid])
        {//pehla part sorted hai
            st = mid + 1;
        }
        else if (v[mid] < v[e])
        {
            e = mid - 1;
        }
    }

    return -1; // If no minimum element is found (this should not happen in a rotated sorted array)
}

int main()
{
    vector<int> v = {11, 13, 14, 15, 2, 4, 6, 7};
    int n = v.size();

    int result = solve(v, n);

    if (result != -1)
    {
        cout << "The minimum element is: " << result << endl;
    }
    else
    {
        cout << "Error: Unable to find the minimum element" << endl;
    }

    return 0;
}
