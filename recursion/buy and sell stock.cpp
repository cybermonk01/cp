#include <bits/stdc++.h>

using namespace std;

void maxProfitFinder(vector<int> &price, int i, int &minPrice, int &maxProfit)
{

    if (i == v.size())
        return;

    if (minPrice > price[i])
        minPrice = price[i];
    int todayProfit = price[i] - minPrice;
    if (todayProfit > maxProfit)
        maxProfit = todayProfit;

    // recursion

    maxProfitFinder(price, i + 1, minPrice, maxProfit);
}

int main()
{

    vector<int> v = {7, 1, 2, 6, 4, 5};
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    maxProfitFinder(v, 0, minPrice, maxProfit);
}