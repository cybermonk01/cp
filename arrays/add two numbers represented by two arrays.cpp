#include <bits/stdc++.h>

using namespace std;

int main()
{

    int arr[] = {2, 1, 0};
    int brr[] = {5, 0};
    string ans;
    int m = 3;
    int n = 2;
    int carry = 0;
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {

        int x = arr[i] + brr[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
    }
    while (i >= 0)
    {

        int x = arr[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
    }
    while (j >= 0)
    {

        int x = 0 + brr[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
    }

    if (carry)
    {
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());

    cout << ans;
}