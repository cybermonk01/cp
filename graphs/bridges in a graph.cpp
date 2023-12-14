void dfs(int node, int &parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, bool> &vis, unordered_map<int, list<pair<int, int>>> &adj)
{

    vis[node] = true;

    low[node] = disc[node] = timer++;

    for (auto nbr : adj[node])
    {

        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, result, vis, adj);
            low[node] = min(low[node], low[nbr]);

            // check if edge is bridge

            if (low[nbr] > disc[node])
            {
                vector<int> ans;

                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {

            // back node hai ye

            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;

    // dfs
    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, result, vis, adj);

            void dfs(int node, int parent, int timer, vector<int> disc, vector<int> low, vector<vector<int>> result, unordered_map<int, bool> vis, unordered_map<int, list<pair<int, int>>> adj)
        }
    }
}