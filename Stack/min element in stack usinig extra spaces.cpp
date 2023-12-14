#include <bits/stdc++.h>

using namespace std;

stack<int> s;
stack<int> ss;

void push(int a)
{
    s.push(a);

    if (ss.empty() || a <= ss.top())
    {
        ss.push(a);
    }
}

int pop()
{
    if (s.empty())
    {
        return -1;
    }
    int ans = s.top();
    s.pop();

    if (ss.top() == ans)
    {
        ss.pop();
    }
    return ans; // You need to return the popped value.
}

int getMin()
{
    if (ss.empty())
    {
        return -1;
    }

    return ss.top();
}

int main()
{
    // You need to define a vector and use the push function to add elements to the stack.
    vector<int> arr = {10, 15, 14, 12, 17, 18};
    for (int i = 0; i < arr.size(); i++)
    {
        push(arr[i]);
    }

    // Now you can use pop and getMin functions as needed.
    int minVal = getMin();
    cout << "Minimum value: " << minVal << endl;

    int poppedVal = pop();
    cout << "Popped value: " << poppedVal << endl;

    minVal = getMin();
    cout << "Minimum value after pop: " << minVal << endl;

    return 0;
}
