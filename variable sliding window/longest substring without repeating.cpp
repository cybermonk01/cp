#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeating(string &s)
{
    int i = 0, j = 0;

    unordered_map<char, int> mp;
    int maxi = 0; // length hai

    while (j < s.length())
    {

        mp[s[j]]++;

        if (mp.size() < j - i + 1)
        {

            while (mp.size() < j - i + 1)
            {

                mp[s[i]]--;

                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }

            j++;
        }
        else if (mp.size() == j - i + 1)
        {

            // ans candidate hai ye
            maxi = max(maxi, j - i + 1);
            j++;
        }

        // yaha mp.size()> j-i+1 wala case nhi ho payega kyuki ek window me jyada object kaise aa skate hai
    }

    return maxi;
}

int main()
{
    string s = "pwwkew";

    int res = longestSubstringWithoutRepeating(s);
    cout << res;

    return 0;
}
