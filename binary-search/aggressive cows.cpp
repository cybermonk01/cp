//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isValid(vector<int> stalls, int n, int k, int maxDist)
    {

        int cow = 1;
        int pos = stalls[0];

        for (auto stall : stalls)
        {

            if ((stall - pos) >= maxDist)
            {
                cow++;
                pos = stall;
            }

            if (cow == k)
            {
                return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here

        sort(stalls.begin(), stalls.end());

        int st = 0;
        int end = stalls[stalls.size() - 1] - stalls[0];
        int res = -1;

        while (st <= end)
        {

            int mid = st + (end - st) / 2;

            if (isValid(stalls, n, k, mid))
            {

                res = mid;
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends