#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v, int n, int ele)
{

    int s = 0, e = n - 1, res = 0;

    while (st <= e)
    {

        int mid = st + (e - st) / 2;

        if (v[mid] == ele)
        {
            return v[mid];
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

    int leftAns = abs(ele - v[e]);
    int rightAns = abs(ele - v[st]); // while loop khatam hone ke baad e st se pehle aa jayega uske baad in differences me se min ans hoga
    int ans = min(leftAns, rightAns);
    return ans;
}

int main()
{

    vector<int> v = {1, 3, 4, 5, 10, 15};
    int n = v.size();
    cout << solve(v, n, 12);
}