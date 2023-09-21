
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(string &s, int i, int j, bool isTrue)
{
    // base condition
    if (i > j)
        return false;

    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }

    string temp = to_string(i);

    temp.append(" ");
    temp.append(to_string(j));
    temp.append(" ");
    temp.append(to_string(isTrue));

    if (mp.find(temp) != mp.end())
    {

        return mp[temp];
    }

    // k loop

    int ans = 0;
    for (int k = i + 1; k <= j; k = k + 2)
    {
        int lT = solve(s, i, k - 1, true);
        int lF = solve(s, i, k - 1, false);
        int rT = solve(s, k + 1, j, true);
        int rF = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
            {
                ans = ans + lT * rT;
            }
            else
            {
                ans = ans + lF * rF + lF * rT + lT * rF;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans = ans + lT * rT + lT * rF + lF * rT;
            }
            else
            {
                ans = ans + lF * rF;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
            {
                ans = ans + lT * rF + lF * rT;
            }
            else
            {
                ans = ans + lT * rT + rF * lF;
            }
        }
    }
    return mp[temp] = ans;
}

int main()
{

    string s = "T&F^T|F";
    int i = 0;
    int j = s.length() - 1;
    bool isTrue = true;
    cout << solve(s, i, j, isTrue);
}
