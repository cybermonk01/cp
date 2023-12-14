#include <bits/stdc++.h>

using namespace std;

void solveLeft(vector<int> &v, vector<int> &leftAns)
{

    int n = v.size();

    stack<pair<int, int>> left;
    int pseudoBuilding = -1;

    for (int i = 0; i < n; i++)
    {

        if (left.empty())
        {
            leftAns.push_back(pseudoBuilding);
        }
        else if (!left.empty() && left.top().first < v[i])
        {
            leftAns.push_back(left.top());
        }
        else if (!left.empty() && left.top().first >= v[i])
        {

            while (!left.empty() && left.top().first >= v[i])
            {
                left.pop();
            }
            if (left.empty())
                leftAns.push_back(pseudoBuilding);
            else if (left.top().first < v[i])
                leftAns.push_back(left.top().second);
        }

        left.push({v[i], i});
    }
}

void solveRight(vector<int> &v, vector<int> &rightAns)
{

    int n = v.size();
    stack<pair<int, int>> right;
    int pseudoBuilding = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (right.empty())
        {
            rightAns.push_back(pseudoBuilding);
        }
        else if (!right.empty() && right.top().first < v[i])
        {
            rightAns.push_back(right.top().second);
        }
        else if (!right.empty() && right.top().first > v[i])
        {

            while (!right.empty() && right.top().first > v[i])
            {
                right.pop();
            }

            if (right.empty())
                rightAns.push_back(pseudoBuilding);
            else if (right.top().first < v[i])
                rightAns.push_back(right.top().second);
        }
        right.push({v[i], i});
    }
}
int main()
{

    vector<int> v = {
        6, 2, 5, 4, 5, 1, 6};
    int n = v.size();
    vector<int> leftAns;
    vector<int> rightAns;
    vector<int> width(n, 0); // Initialize width vector with zeros
    vector<int> area(n, 0);
    int maxi = INT_MIN;
    solveLeft(v, leftAns);
    solveRight(v, rightAns);

    for (int i = 0; i < n; i++)
    {
        width[i] = rightAns[i] - leftAns[i] - 1;
        area[i] = width[i] * i;
        maxi = max(maxi, area[i]);
        cout << "max area histogram is " << maxi << endl;
    }
}
