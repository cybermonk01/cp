#include <iostream>
#include <stack>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

void solveLeft(vector<int> &v, vector<int> &left)
{

    int n = v.size();
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {

        int pseudoIndex = -1;
        if (st.empty())
        {
            left.push_back(pseudoIndex);
        }
        else if (!st.empty() && st.top().first < v[i])
        {
            left.push_back(st.top().second);
        }
        else if (!st.empty() && st.top().first >= v[i])
        {
            while (!st.empty() && st.top().first >= v[i])
            {
                st.pop();
            }

            if (st.empty())
                left.push_back(pseudoIndex);
            else if (st.top().first < v[i])
                left.push_back(st.top().second);
        }

        st.push({v[i], i});
    }
}

void solveLeft(vector<int> &v, vector<int> &right)
{

    int n = v.size();
    stack<pair<int, int>> st;
    while (!st.empty())
    {

        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {

        int pseudoIndex = n;
        if (st.empty())
        {
            right.push_back(pseudoIndex);
        }
        else if (!st.empty() && st.top().first < v[i])
        {
            right.push_back(st.top().second);
        }
        else if (!st.empty() && st.top().first >= v[i])
        {
            while (!st.empty() && st.top().first >= v[i])
            {
                st.pop();
            }

            if (st.empty())
                right.push_back(pseudoIndex);
            else if (st.top().first < v[i])
                right.push_back(st.top().second);
        }

        st.push({v[i], i});
    }
    reverse(right.begin(), right.end());
}

int MAH(vector<int> v)
{

    vector<int> left;
    solveLeft(v, left);
    vector<int> right;
    solveRight(v, right);
    vector<int> width(n, 0);
    vector<int> area(n, 0);
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }

    for (int i = 0; i < n; i++)
    {
        area[i] = width[i] * i;
        maxi = max(maxi, area[i]);
    }
    return maxi;
}
int main()
{

    int arr[][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    vector<int> v;
    int n = 4, m = 4;

    for (int j = 0; j < m; j++)
    {

        v.push_back(arr[0][j]);
    }

    int maxi = MAH(v);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] += arr[i][j];
            }
        }
        maxi = max(maxi, MAH(v));
    }
    cout << "max area is " << maxi << endl;

    return 0;
}
