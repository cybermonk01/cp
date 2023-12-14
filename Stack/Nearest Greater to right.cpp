#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int> &v, vector<int> &ans)
{

    stack<int> s;

    for (int i = v.size() - 1; i >= 0; i--)
    {

        if (s.size() == 0)
        {
            ans.push_back(-1);
        }

        else if (s.size() > 0 && s.top() > v[i])
        {
            ans.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= v[i])
        {

            while (s.size() > 0 && s.top() <= v[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {

                ans.push_back(s.top());
            }
        }

        s.push(v[i]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans;
    solve(arr, ans);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    return 0;
}

/********************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v = {1, 3, 2, 4};
    stack<int> st;
    int n = v.size();
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        st.push(v[i]);

        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top() > v[i])
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() <= v[i])
        {
            while (st.size() > 0 && st.top() <= v[i])
            {
                st.pop();
            }

            if (st.empty())
                ans.push_back(-1);
            else if (st.top() > v[i])
                ans.push_back(st.top());
        }
        st.push(v[i]);
    }

    reverse(ans.begin(), ans.end());
    for (auto val : ans)
    {
        cout << val << " ";
    }
}