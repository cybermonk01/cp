#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int cap, int n)
{
    if (n == 0 || cap == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= cap)
    {
        return max(val[n - 1] + knapsack(wt, val, cap - wt[n - 1], n - 1), knapsack(wt, val, cap, n - 1));
    }
    else
    {
        return knapsack(wt, val, cap, n - 1);
    }
}

int main()
{

    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int cap = 50;

    int n = wt.size();
    cout << knapsack(wt, val, cap, n);
}