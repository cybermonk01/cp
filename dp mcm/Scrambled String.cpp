#include <bits/stdc++.h>

using namespace std;

bool solve(string &s1, string &s2)
{

    if (s1.compare(s2) == 0)
        return true;

    if (s1.length() <= 1)
        return false;

    int n = s1.length();
    int flag = false;

    for (int i = 1; i < s1.length() - 1; i++)
    {

        int cond1 = solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i));

        int cond2 = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i));

        if (cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{

    string s1 = "great";
    string s2 = "ategr";

    cout << (solve(s1, s2)
             : "scrambled hai"
             : "scrambled nhi hai");
}