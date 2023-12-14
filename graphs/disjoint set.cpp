#include <bits/stdc++.h>

using namespace std;

class DisjointSet()
{
public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        // har node ka parent wahi rahega

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {

        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int>
        parent;
    vector<int> rank;
}

int main()
{
    int n = 5; // Number of elements

    DisjointSet ds(n);

    // Example usage:
    ds.unionSets(0, 1);
    ds.unionSets(2, 3);
    ds.unionSets(0, 4);

    for (int i = 0; i < n; i++)
    {
        std::cout << "Element " << i << " belongs to set with representative " << ds.find(i) << std::endl;
    }

    return 0;
}

const int N = 1e9;

int parent[N];

void make(int v)
{
    // har node ka parent khud ko bana do
    parent[v] = v;
}

int find(int v)
{
    if (v == parent[v])
        return v; // agar wo khud ka parent hai to return

    return find(parent[v]);
}