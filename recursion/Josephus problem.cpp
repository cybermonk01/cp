#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &v, int index, int k, int ans)
{
    if (v.size() == 0)
    {
        ans = v[0];
        return;
    }

    index = (index + k) % v.size();
    v.erase(v.begin() + index);

    solve(v, index, k, ans);
}

int main()
{

    int n = 40, k = 7;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }

    int ans = 0;
    int index = 0;
    solve(v, index, k, ans);
    cout << ans;
}