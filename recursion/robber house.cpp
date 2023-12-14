// ghar lootne hai alternate  nhi kar sakte

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &v, int i)
{

    if (i >= v.size())
        return 0;

    int rob1 = v[i] + rob(v, i + 2);
    int rob2 = 0 + rob(v, i + 1);

    int ans = max(rob1, rob2);

    return ans;
}

int main()
{

    vector<int> v = {2, 1, 1, 2};
    int i = 0;
    int ans = rob(v, i);
    cout << ans;
}