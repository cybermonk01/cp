#include <bits/stdc++.h>

using namespace std;

int kLarge(vector<int> &v, int k)
{

    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < v.size(); i++)
    {

        minh.push(v[i]);

        if (minh.size() > k)
        {
            minh.pop();
        }
    }

    return minh.top();
}

int main()
{

    vector<int> v = {2, 7, 8, 9, 4, 5, 6};
    int k = 3;

    int ans = kLarge(v, k);
    cout << "kth Largest element is " << ans;
}