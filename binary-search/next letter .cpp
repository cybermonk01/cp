#include <bits/stdc++.h>

using namespace std;

char solve(vector<char> v, int n, char ele)
{

    int st = 0, e = n - 1, res = 0;

    while (st <= e)
    {

        int mid = (st + e) / 2;

        if (v[mid] == ele)
        {
            st = mid + 1;
        }
        else if (v[mid] < ele)
        {
            st = mid + 1;
        }
        else if (v[mid] > ele)
        {
            res = v[mid - 1];
            e = mid - 1;
        }
    }
    return res;
}

int main()
{

    vector<char> v = {a, c, f, h};
    int n = v.size();
    char ele = 'f';
    solve(v, n, ele);
}