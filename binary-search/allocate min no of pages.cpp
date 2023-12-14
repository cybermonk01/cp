#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<int> &v, int n, int k, int maxi)
{

    int sum = 0;
    int student = 1;

    for (auto val : v)
    {
        sum += val;
        if (sum > maxi)
        {
            student++;
            sum = val;
        }
        if (student > k)
        {
            return false;
        }
    }
    return true;
}

int solve(vector<int> &v, int n, int k)
{

    if (n < k)
        return -1;

    int maxi = INT_MIN, sum = 0;
    for (auto val : v)
    {
        sum += val;
        maxi = max(maxi, val);
    }

    int st = maxi;
    int e = sum;
  int res = 0;

    while (st <= e)
    {
        int mid = st + (e - st) / 2;

        if (isValid(v, n, k, mid))
        {
            res = mid;
            e = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
      return res;
  
}

int main()
{

    vector<int> v = {10, 20, 30, 40};
    int k = 2;
    int n = v.size();

   cout<< solve(v, n, k);
}