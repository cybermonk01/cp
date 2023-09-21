#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> firstNeg(vector<int> v, int k, int i, int j)
{
    list<int> l;
    vector<int> result;

    while (j < v.size())
    {
        if (v[j] < 0)
        {
            l.push_back(v[j]);
        }

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            // calculations

            if (l.size() == 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(l.front());

                if (v[i] == l.front())
                {
                    l.pop_front();
                }
            }

            // Increment both i and j outside the 'else' block
            i++;
            j++;
        }
    }

    return result;
}

int main()
{
    vector<int> v = {1, -1, -2, 10, -23, -3, 1, 0, 20};
    int k = 4;
    int i = 0;
    int j = 0;

    vector<int> ans = firstNeg(v, k, i, j);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0; // Add a return statement at the end of the 'main' function
}
