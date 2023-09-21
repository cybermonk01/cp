#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &arr)
{

    int l = 0, curr = 0, h = n - 1;

    while (curr <= h)
    {

        if (arr[curr] == 0)
        {
            swap(arr[l], arr[curr]);
            l++;
            curr++;
                }
        else if (arr[curr] = 2)
        {
            swap(arr[h], arr[curr]);
            h--;
        }
        else
        {
            curr++;
        }
    }

    for (auto val : v)
    {
        cout << val << " ";
    }
}

int main()
{

    vector<int> arr = {2, 1, 1, 0, 2, 2, 0};

    int n = arr.size();
    sortColors(arr, n);
}
