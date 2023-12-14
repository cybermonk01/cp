#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int top)
{

    if (s.empty() || s.top() <= top)
    {
        s.push(top);
        return;
    }

    int top1 = s.top();
    s.pop();

    insert(s, top);

    s.push(top1);
}

void sort(stack<int> &s)
{

    if (s.size() == 1)
    {
        return;
    }

    // agar size jyada hai to pop karo fir sort karo

    int top = s.top();
    s.pop();

    sort(s);

    insert(s, top);
}
int main()
{

    stack<int> s;
    vector<int> elements = {2, 1, 3, 6, 4, 5};

    // Push elements onto the stack
    for (int element : elements)
    {
        s.push(element);
    }

    sort(s);

    // Print the sorted elements
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}