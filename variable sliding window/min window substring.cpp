
#include <bits/stdc++.h>
using namespace std;

string minSub(string &s1, string &s2)
{
    unordered_map<char, int> targetFreq, windowFreq;
    for (char c : s2)
    {
        targetFreq[c]++;
    }

    int i = 0, j = 0;
    int minLen = INT_MAX;
    int minStart = 0;
    int remaining = s2.length();

    while (j < s1.length())
    {
        if (targetFreq.find(s1[j]) != targetFreq.end())
        {
            windowFreq[s1[j]]++;
            if (windowFreq[s1[j]] <= targetFreq[s1[j]])
            {
                remaining--;
            }
        }

        while (remaining == 0)
        {
            if (j - i + 1 < minLen)
            {
                minLen = j - i + 1;
                minStart = i;
            }

            if (targetFreq.find(s1[i]) != targetFreq.end())
            {
                windowFreq[s1[i]]--;
                if (windowFreq[s1[i]] < targetFreq[s1[i]])
                {
                    remaining++;
                }
            }
            i++;
        }
        j++;
    }

    if (minLen == INT_MAX)
    {
        return "";
    }
    else
    {
        return s1.substr(minStart, minLen);
    }
}

int main()
{
    string s = "TOTMTAPTA";
    string t = "TTA";

    string result = minSub(s, t);

    if (result.empty())
    {
        cout << "No minimum window substring found." << endl;
    }
    else
    {
        cout << "Minimum window substring: " << result << endl;
    }

    return 0;
}
