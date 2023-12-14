#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int arr[], int n, int k, long long sol)
    {
        int painters = 1;
        long long totalTime = 0;

        for (int i = 0; i < n; i++)
        {
            totalTime += arr[i];
            if (totalTime > sol)
            {
                painters++;
                totalTime = arr[i];
            }
            if (painters > k)
            {
                return false;
            }
        }

        return true;
    }

    long long minTime(int arr[], int n, int k)
    {
        long long sum = 0, maxi = LLONG_MIN;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxi = max(maxi, (long long)arr[i]);
        }

        long long st = maxi;
        long long end = sum;

        while (st <= end)
        {
            long long mid = (st + end) / 2;
            if (isPossible(arr, n, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minTime(arr, n, k) << endl;
    }
    return 0;
}
