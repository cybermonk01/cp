#include <bits/stdc++.h>

using namespace std;

void solve(int zeroes, int ones, int n, string op)
{

    if (n == 0)
    {
        cout << op << " ";
        return;
    }

    if (ones > zeroes)
    {

        string op1 = op;
        op1.push_back('0');

        solve(zeroes + 1, ones, n - 1, op1);
    }
    else
    {

        string op2 = op;
        op2.push_back('1');

        solve(zeroes, ones + 1, n - 1, op2);
    }
}

int main()
{

    int n = 3;

    int ones = 0;
    int zeroes = 0;

    string op = "";

    solve(zeroes, ones, n, op);
}