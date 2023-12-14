

// kisi bhi number ka module 10^9 + 7  ka matlab hai kisi bhi bade answer ka hum module nikal ke use int me store kar sakte hai
// aur saath hi saath ye number int ki max limit ke close hai to saare answer int me store ho jaate hai

// aur ye number prime hai jiske karan hum kisi bhi number ka multiplicative inverse nikal sakte hai

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "enter number ";
    cin >> n;
    int M = 47; // iska matlab hai ki answer is number se jyada nhi aayega

    long long fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact = (fact * i) % M;
    }

    cout << "factorial of " << n << " is " << fact << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<pair<int, int>> graph = {{0, 1}, {1, 2}, {1, 3}, {3, 12}};

    vector<vector<int>> adj;
    for (auto pair : graph)
    {
        int u = pair.first;
        int v = pair.second;

        adj[u].push_back(v);
    }
}
