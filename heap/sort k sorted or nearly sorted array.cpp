#include <bits/stdc++.h>

using namespace std;

vector<int> sortKSortedArray(vector<int> &arr, int k)
{

    vector<int> result;

    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i <= k; i++)
    {
        minh.push(arr[i]);
    }

    for (int i = k + 1; i < arr.size(); i++)
    {

        result.push_back(minh.top());
        minh.pop();

        minh.push(arr[i]);
    }

    while (arr)
    {
        result.push_back(minh.top());
        minh.pop();
    }
    return result;
}

int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> sortedArray = sortKSortedArray(arr, k);

    cout << "Sorted Array: ";
    for (int num : sortedArray)
    {
        cout << num << " ";
    }

    return 0;
}