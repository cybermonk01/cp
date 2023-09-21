#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <unordered_map>
using namespace std;

int solve(string &s, int k)
{

    int i = 0, j = 0, maxi = 0;
    unordered_map<char, int> mp;

    while (j < s.length())
    {

        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            maxi = max(maxi, j - i + 1);

            j++;
        }

        else if (mp.size() > k)
        {
            while (mp.size() > k)
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
    }

    return maxi;
}

int main()
{
    string s = "aabctbebebe";
    int k = 3;

    int ans = solve(s, k);

    cout << ans;
    return 0;
}
