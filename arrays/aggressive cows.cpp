#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &stalls, int cows, int minDis)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {

        if (stalls[i] - lastPos >= minDis)
        {
            cowCount++;
            lastPos = stalls[i];
        }
    }
    return cowCount >= cows;
}

int largestMinDistance(vector<int> &stalls, int cows)
{
    int low = 0;
    int high = stalls[stalls.size() - 1] - stalls[0];
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(stalls, cows, mid))
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int main()
{
    int cows, n;

    cout << "enter number of cows" << ;
    cin >> cows;

    cout << "enter number of stalls";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter the positions of stalls: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    int result = largestMinDistance(stalls, cows);
    cout << "The largest minimum distance to place cows is: " << result << endl;

    return 0;
}