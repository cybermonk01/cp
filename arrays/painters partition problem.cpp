#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &boards, int painter, int maxBoard)
{

    int painterCount = 1;
    int lastBoard = boards[0];

    for (int i = 1; i < boards.size(); i++)
    {
        if (boards[i] - lastBoard >= maxBoard)
        {
            painterCount++;
            lastBoard = boards[i];
        }
    }
    return painterCount >= painter;
}

int minTime(vector<int> &boards, int painter)
{

    int st = 0;
    int e = boards[boards.size() - 1] - boards[0];
    int result = -1;

    while (st <= e)
    {

        int mid = (st + e) >> 1;

        if (isPossible(boards, painter, mid))
        {
            result = mid;
            e = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return res;
}

int main()
{

    int n, painters;
    cout << "enter number of boards ";
    cin >> n;

    cout << "enter number of painters ";
    cin >> painters;

    vector<int> boards(n);
    cout << "Enter the positions of boards: ";
    for (int i = 0; i < n; i++)
    {
        cin >> boards[i];
    }

    int result = minTime(boards, painters);
    cout << "The min time  is: " << result << endl;

    return 0;
}