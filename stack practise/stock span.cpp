#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &v, vector<int> &ans)
{

    stack<pair<int, int>> st;

    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (!st.empty() && st.top().first > v[i])
        {
            ans.push_back(st.top().second);
        }
        else if (!st.empty() && st.top().first <= v[i])
        {

            while (!st.empty() && st.top().first <= v[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({v[i], i});
    }

    for (int i = 0; i < v.size(); i++)
    {

        ans[i] = i - ans[i];
    }
}

int main()
{

    vector<int> v = {100,
                     80,
                     60,
                     70,
                     60,
                     75,
                     85};

    vector<int> ans;

    solve(v, ans);
}