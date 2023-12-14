#include <bits/stdc++.h>

using namespace std;

void permute(string ip, string op, vector<string> &v)
{

    if (ip.length() == 0)
    {
        v.push_back(op);
        return;
    }

    set<char> mp;

    for (int i = 0; i < ip.length(); i++)
    {

        if (mp.find(ip[i]) == mp.end())
        {

            mp.insert(ip[i]);

            string newIp = ip.substr(0, i) + ip.substr(i + 1);

            string newOp = op + ip[i];

            permute(newIp, newOp, v);
        }
    }
}
int main()
{

    string ip = "abc";

    string op = "";

    vector<string> v;

    permute(ip, op, v);

    for (auto val : v)
    {
        cout << val << " ";
    }
}