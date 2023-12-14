#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int parent[N];
int size[N];
void make(int v)
{

    parent[v] = v;
    size[v] = 1;
}

void findParent(int v)
{

    if (v == parent[v])
        return v;

    return parent[v] = findParent(parent[v]);
}

void Union(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int m, n;
    cout << "enter edges and nodes";
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        make[i];
    }

    while (m--)
    {

        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int components;
    for (int i = 0; i < n; i++)
    {

        if (findParent(v))
            components++;
    }
    cout << "no of components" << components;
}