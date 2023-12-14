#include <bits/stdc++.h>

using namespace std;

void solve(int open, int close, string &op, vector<string> &v)
{

    if (open == 0 && close == 0)
    {
        v.push_back(op);
        return;
    }

    string op1 = op;
    string op2 = op;

    if (open != 0)
    {
        op1.push_back('(');

        solve(open - 1, close, op1, v);
    }

    if (close > open)
    {
        op2.push_back(')');

        solve(open, close - 1, op2, v);
    }
}

vector<string> generate(int n)
{

    int close = n;
    int open = n;
    string op = " ";

    vector<string> v;
    solve(open, close, op, v);
    return v;
}

int main()
{

    int n = 3;
    vector<string> ans = generate(n);

    for (auto val : ans)
    {
        cout << val << endl;
    }
}