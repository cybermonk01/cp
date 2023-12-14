#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> solve(vector<int> v, int k)
{
    vector<int> result;

    unordered_map<int, int> mp;

    priority_queue<pii, vector<pii>, greater<pii>> minhp;

    for (auto val : v)
    {
        mp[val]++;
    }

    for (int i = mp.begin(); i < mp.end(); i++)
    {

        minhp.push({mp.second, mp.first});

        if (minhp.size() > k)
        {
            minhp.pop();
        }
    }

    while (!minhp.empty())
    {
        result.push_back(minhp.top());
        minhp.pop();
    }
}

int main()
{

    vector<int> v = {1, 1, 2, 2, 5, 6, 5};

    int k = 2;

    vector<int> ans = solve(v, k);

    for (auto val : ans)
    {
        cout << val << " ";
    }
}