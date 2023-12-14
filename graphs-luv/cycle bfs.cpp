
bool isCyclicBFS(int start, vector<bool> &vis, unordered_int<int, int> &parent)
{

    queue<int> q;

    q.push(start);
    vis[start] = true;
    parent[start] = -1;

    while (!q.empty())
    {

        int curr = q.front();
        q.pop();

        for (auto nbr : adj[curr])
        {

            if (!vis[nbr])
            {
                q.push(nbr);
                vis[nbr] = true;
                parent[nbr] = curr;
            }
            else if (vis[nbr] && parent[nbr] != curr)
            {
                return true;
            }
        }
    }
    return false;
}