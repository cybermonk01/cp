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

// method 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <list>

using namespace std;

vector<int> maximum(vector<int> &v, int k)
{

    int n = v.size();
    int i = 0, j = 0;
    int maxi = INT_MIN;
    vector<int> ans;

    list<int> l;

    while (j < n)
    {

        // list me daalo aur
        if (l.size() != 0 && l.back() < v[j])
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

            maxi = l.front();
            ans.push_back(maxi);

            // aage badhao

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
