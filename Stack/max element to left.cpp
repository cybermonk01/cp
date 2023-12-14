#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v = {1, 3, 2, 4};
    stack<int> st;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        st.push(v[i]);

        if (st.empty())
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top() > arr[i])
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() < arr[i])
        {
            while (st.size() > 0 && st.top() < arr[i])
            {
                st.pop();
            }
        }
        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    for (auto val : ans)
    {
        cout << val << " ";
    }
}