#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<pair<int, int>> &numbers)
{

    if (n == 0)
        return "zero";

    for (auto it : numbers)
    {

        if (n >= it.first)
        {

            string a = "";
            if (n >= 100)
            {

                a = solve(n / it.first);
            }
            string b = it.second;

            string c = "";
            if (n % it.first != 0)
                c = solve(n % it.first);
            return a + b + c;
        }
    }
}

int main()
{

    vector<pair<int, string>> numbers = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {100, "hundred"}, {1000, "thousand"}};

    int n;
    cout << "enter number";
    cin >> n;

    string ans = solve(n, numbers);
    cout << ans;
}