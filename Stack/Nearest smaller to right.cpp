#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int> &v, vector<int> &ans)
{

    stack<int> s;

    for (int i = v.size() - 1; i >= 0; i++)
    {

        if (s.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > v[i])
        {
            while (s.size() > 0 && s.top() > v[i])
                s.pop();

            if (s.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {

                ans.push_back(s.top());
            }
        }

        else if (s.size() > 0 && s.top() <= v[i])
        {

            ans.push_back(s.top());
        }

        s.push(v[i]);
    }

    return ans;
}

int main()
{

    vector<int> v = {4, 3, 2, 10, 8};

    vector<int> ans;

    solve(v, ans);

    return 0;
}