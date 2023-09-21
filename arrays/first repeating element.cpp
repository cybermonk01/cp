#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> mp;

int solve(vector<int> &v, int n)
{

    for (auto val : v)
    {
        mp[val]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] > 1)
        {
            return i + 1;
            break;
        }
    }
    return -1;
}

int main()
{

    vector<int> v = {1, 5, 3, 6, 4, 5, 3};

    int n = v.size();
    cout << solve(v, n);
}