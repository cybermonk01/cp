#include <bits/stdc++.h>
using namespace std;

void bfs(int st, vector<int> &visited, vector<int> &parent, unordered_map<int, list<int>> &adj, int dest) {
    queue<int> q;
    q.push(st);
    visited[st] = true;
    parent[st] = -1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int nbr : adj[front]) {
            if (!visited[nbr]) {
                q.push(nbr);
                visited[nbr] = true;
                parent[nbr] = front;
            }
        }
    }
}

vector<int> shortest(vector<pair<int, int>> edges, int n, int st, int dest) {
    unordered_map<int, list<int>> adj;
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph, add the reverse edge.
    }

    vector<int> visited(n);
    vector<int> parent(n);

    bfs(st, visited, parent, adj, dest);

    vector<int> ans;
    int currNode = dest;

    if (parent[currNode] == -1) {
        // No path from 'st' to 'dest' was found.
        return ans;
    }

    while (currNode != -1) {
        ans.push_back(currNode);
        currNode = parent[currNode];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 5}, {5, 7}, {7, 8}, {2, 6}, {6, 8}, {4, 12}, {12, 8}};
    vector<int> ans = shortest(edges, 9, 1, 8);

    if (ans.empty()) {
        cout << "No path from 1 to 8" << endl;
    } else {
        for (int val : ans) {
            cout << val << " ";
        }
    }

    return 0;
}
