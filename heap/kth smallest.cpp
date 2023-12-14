#include <bits/stdc++.h>

using namespace std;

int kSmall(vector<int> &v, int n, int k)
{

    priority_queue<int> maxh;

    for (int i = 0; i < n; i++)
    {
        maxh.push(v[i]);

        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    return maxh.top();
}

int main()
{

    vector<int> v = {2, 4, 15, 7, 8, 9, 6, 1};
    int n = v.size();
    int k = 3;
    int ans = kSmall(v, n, k);
    cout << "kth smallest element is" << ans;
}