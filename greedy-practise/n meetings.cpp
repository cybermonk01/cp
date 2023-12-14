#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int solve(vector<int> &a, vector<int> &b)
{

    vector<pair<int, int>> v;

    for (int i = 0; i < a.size(); i++)
    {

        v.push_back({a[i], b[i]});
    }

    sort(v.begin(), v.end(), cmp);

    int count = 0;
    int endAns = v[0].second;

    for (int i = 1; i < a.size(); i++)
    {

        if (endAns < v[i].first)
        {

            count++;
            endAns = v[i].second;
        }
    }
    return count;
}

int main()
{

    vector<int> a = {1, 3, 2, 5};
    vector<int> b = {2, 4, 3, 6};
    int n = a.size();

    cout << solve(a, b, n);
}