class Solution
{
public:
    bool topoKahn(int n, unordered_map<int, list<int>> &adj)
    {
        queue<int> q;

        unordered_map<int, int> indegree;

        for (auto i : adj)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {

            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto nbr : adj[frontNode])
            {

                indegree[nbr]--;

                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        if (ans.size() == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        unordered_map<int, list<int>> adj;
        for (auto tasks : prerequisites)
        {

            int u = tasks[0];
            int v = tasks[1];

            adj[v].push_back(u);
        }

        bool ans = false;

        ans = topoKahn(numCourses, adj);

        return ans;
    }
};