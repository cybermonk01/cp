#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, int isDirected)
    {
        adjList[u].push_back(v);

        if (isDirected == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {

        for (auto i : adjList)
        {
            cout << i.first << " -> ";

            for (auto val : i.second)
            {
                cout << val << ",";
            }

            cout << endl;
        }
    }

    void BFS(int start)
    {

        unordered_map<int, bool> visited;

        queue<int> q;
        vector<int> ans;

        for (auto &pair : adjList)
        {
            visited[pair.first] = false;
        }

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {

            int curr = q.front();
            ans.push_back(curr);
            cout << curr << " ";
            q.pop();

            for (auto neighbour : adjList[curr])
            {

                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void DFS(int start)
    {
        unordered_map<int, bool> visited;
        queue<int> q;

        for (auto &pair : adjList)
        {
            visited[pair.first] = false;
        }

        q.push(start);

        visited[start] = true;

        for (auto neighbour : adjList[start])
        {
            if (!visited[neighbour])
            {
                DFS(neighbour);
            }
        }
    }

    bool isCyclic(int n)
    {

        unordered_map<int, bool> visited;
        queue<pair<int, int>> q;

        for (auto &pair : adjList)
        {
            visited[pair.first] = true;
        }

        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                q.push({i, -1});
                visited[i] = true;

                while (!q.empty())
                {

                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for (int neighbour : adjList[node])
                    {
                        if (!visited[neighbour])
                        {
                            visited[neighbour] = true;
                            q.push({neighbour, node});
                        }
                        else if (parent != neighbour)
                            return true;
                    }
                }
            }
        }

        return false;
    }

    bool isCyclicDFSUtil(int start, unordered_map<int, bool> &visited, int parent)
    {

        visited[start] = true;
        for (auto neighbor : adjList[start])
        {

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                if (isCyclicDFSUtil(neighbor, visited, parent))
                    return true;
                else if (parent != neighbor)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(int n)
    {
        unordered_map<int, bool> visited;

        for (auto &pair : adjList)
        {
            visited[pair.first] = false;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && isCyclicDFSUtil(i, visited, -1))
                return true;
        }
        return false;
    }
};

int main()
{

    int m, n;

    cout << "enter the number of nodes";
    cin >> m;

    cout << "enter number of edges";
    cin >> n;

    graph g;
    for (int i = 0; i < n; i++)
    {

        int u, v;

        cin >> u >> v;

        g.addEdge(u, v, 0);
    }
    g.printGraph();
    cout << endl;

    cout << "bfs "
         << "-> ";
    g.BFS(1);
    cout << "DFS -> ";
    g.DFS(1);
    cout << endl;

    if (g.isCyclic(m))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    if (g.isCyclicDFS(m))
    {
        cout << "The graph contains a cycle DFDDFDFDFFDF." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }
}
