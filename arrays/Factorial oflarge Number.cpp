#include <bits/stdc++.h>

using namespace std;

int main()
{

    int num = 7;
    vector<int> ans;
    int i = 1;
    ans.push_back(i);

    int carry = 0;
    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        if (carry)
        {
            ans.push_back(carry);
        }
        carry = 0;
    }

    reverse(ans.begin(), ans.end());

    for (auto val : ans)
    {
        cout << val << " ";
    }
}