#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> v, int n, int k)
{

    priority_queue<pair<int, int>> maxhp;
    vector<int> result;

    for (int i = 0; i < v.size(); i++)
    {
        maxhp.push({abs(v[i] - n), v[i]});

        if (maxhp.size() > k)
        {
            maxhp.pop();
        }
    }

    while (!maxhp.empty())
    {
        result.push_back(maxhp.top().second);
        maxhp.pop();
    }
    return result;
}

int main()
{

    vector<int> v = {4, 5, 6, 7, 8, 9};
    int n = 7;
    int k = 4;

    vector<int> ans = solve(v, n, k);

    for (auto val : ans)
    {
        cout << val << " ";
    }
}