#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int top)
{
    if (st.size() == 0)
    {
        st.push(top);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st, top);
    st.push(temp);
}

stack<int> revers(stack<int> &st)
{
    if (st.size() == 1)
    {
        return st;
    }

    int top = st.top();
    st.pop();
    revers(st);
    insert(st, top);
    return st;
}

int main()
{
    vector<int> v = {2, 3, 4, 5, 6, 7};
    stack<int> st;
    for (auto val : v)
    {
        st.push(val);
    }

    // // Print original stack
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    // Reverse the stack
    stack<int> reversedStack = revers(st);

    // Print reversed stack
    while (!reversedStack.empty())
    {
        cout << reversedStack.top() << " ";
        reversedStack.pop();
    }

    return 0;
}
