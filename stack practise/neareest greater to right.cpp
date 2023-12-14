#include <bits/stdc++.h>

using namespace std;

void ngr(vector<int> &v, vector<int> &ans)
{

    stack<int> st;

    for (int i = v.size() - 1; i >= 0; i--)
    {

        if (st.empty())
            ans.push_back(-1);

        else if (!st.empty() && v[i] < st.top())
        {
            ans.push_back(st.top());
        }
        else if (!st.empty() && v[i] >= st.top())
        {

            while (!st.empty() && v[i] >= st.top())
            {

                st.pop();
            }

            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(v[i]);
    }

    reverse(ans.begin(), ans.end());
}

int main()
{

    vector<int> v = {1, 3, 0, 2, 4};
    vector<int> ans;
    ngr(v, ans);

    for (auto val : ans)
    {
        cout << val << " ";
    }
}