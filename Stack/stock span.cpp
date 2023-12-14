#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &v, vector<int> &ans)
{
    int n = v.size();
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
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
                ans.push_back(-1);
            else if (st.top().first > v[i])
                ans.push_back(st.top().second);
        }

        st.push({v[i], i});
    }
}

int main()
{

    vector<int> v = {100, 80, 60, 70, 75, 85};
    int n = v.size();
    vector<int> ans;

    solve(v, ans);
    // here ans vector will have the index of the ngl element
    // as we have to get stock span we will  i - ans[i];
    for (auto val : ans)
    {
        cout << val << " ";
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = i - ans[i];
    }
    cout << "after ans" << endl;
    for (auto val : ans)
    {
        cout << val << " ";
    }
}