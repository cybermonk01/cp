#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solve(vector<int> start, vector<int> end, int n)
{

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int ansEnd = v[0].second;

    // pehla case to aayega hi so count = 1 uske baad agle element se iterate karnege aur dekhenge ki ki agele element ka starting time , pehli meeting ke ending time se bada hona chahiye tabhi wo meeting kar payenge then count++
    for (int i = 1; i < n; i++)
    {

        if (v[i].first > ansEnd)
        {
            count++;
            ansEnd = v[i].second;
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