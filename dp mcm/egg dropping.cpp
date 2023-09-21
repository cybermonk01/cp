#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;

int solve(int e, int f)
{
    string key = to_string(e) + " " + to_string(f);
    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;

    if (mp.find(key) != mp.end())
        return mp[key];

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {

        int breake = solve(e - 1, k - 1);
        int noBreak = solve(e, f - k);

        int tempAns = 1 + max(breake, noBreak);

        mini = min(mini, tempAns);
    }
    mp[key] = mini;

    // for (auto val : mp) {
    //     cout << val.first <<":";
    //     cout << val.second << endl;
    // }
    return mini;
}

int main()
{

    int e = 3;
    int f = 5;

    cout << solve(e, f);

    return 0;
}