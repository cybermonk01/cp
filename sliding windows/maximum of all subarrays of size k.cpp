#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int> maximum(vector<int> &v, int k)
{
    int i = 0, j = 0;
    list<int> l;
    vector<int> ans;

    while (j < v.size())
    {
        while (!l.empty() && l.back() < v[j])
        {
            l.pop_back();
        }
        l.push_back(v[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());

            // Slide the window
            if (l.front() == v[i])
            {
                l.pop_front();
            }

            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {5, 8, 4, -1, 2, 3, 6};
    int k = 3;

    vector<int> ans = maximum(v, k);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
