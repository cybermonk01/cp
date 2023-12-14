#include <bits/stdc++.h>

using namespace std;

bool solve(int S, int N, int M)
{
    int sundays = S / 7; // un dino me no of sundays milenge

    int buyingDays = S - sundays;

    int totalFood = buyingDays * M;
    int ans = 0;
    if (totalFood % N == 0)
    {
        ans = totalFood % N;
    }
    else
    {
        ans = toalFood / N + 1;
    }

    if (ans <= buyingDays)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int main()
{

    int surviveDays = 10;
    int requiredFood = 2;
    int shopUnits = 8;

    cout << solve(surviveDays, shopUnits, requiredFood);
}