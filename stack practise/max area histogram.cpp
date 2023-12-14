#include <bits/stdc++.h>
using namespace std;

void minL(vector<int> &v, vector<int> &left)
{
    int pseudoIndex = -1;

    stack<pair<int, int>> st;

    for (int i = 0; i < v.size(); i++)
    {

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
            {
                left.push_back(pseudoIndex);
            }
            else
            {
                left.push_back(st.top().second);
            }
        }

        st.push({v[i], i});
    }
}

void minR(vector<int> &v, vector<int> &right)
{
    int pseudoIndex = v.size();

    stack<pair<int, int>> st;

    for (int i = v.size() - 1; i >= 0; i--)
    {

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
            {
                right.push_back(pseudoIndex);
            }
            else
            {
                right.push_back(st.top().second);
            }
        }

        st.push({v[i], i});
    }
    reverse(right.begin(), right.end());
}
int main()
{
    vector<int> v = {6, 2, 5, 4, 5, 1, 6};
    vector<int> left, right;

    minL(v, left);
    minR(v, right);

    vector<int> width(v.size()); // Initialize width vector with the same size as v

    for (int i = 0; i < v.size(); i++)
    {
        width[i] = right[i] - left[i] - 1;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        maxi = max(maxi, v[i] * width[i]);
    }

    cout << "Max area of histogram is " << maxi << endl;

    return 0;
}
