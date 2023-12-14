#include <bits/stdc++.h>

using namespace std;

void deleted(stack<int> &st, int k)
{

    if (k == 1)
    {
        st.pop();
        return;
    }
    int top = st.top();
    st.pop();

    deleted(st, k - 1);

    st.push(top);
}

int main()
{

    vector<int> v = {2, 3, 4, 5, 6, 7};
    stack<int> s;
    for (auto val : v)
    {
        s.push(val);
    }

    int k = s.size() / 2 + 1;

    deleted(s, k);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}