#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    int n = v.size() - 1;
    for (auto val : v)
    {
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < ans.size(); j++)
            {
                int x = v[j] * i + carry;
                ans[j] = x % 10;
                carry = x / 10;
            }

            while (carry)
            {
                ans.push_back(carry % 10);
                carry = carry / 10;
            }
        }
        for (auto val : ans)
        {
            cout << val << " ";
        }
        reverse(ans.begin(), ans.end());
    }
}