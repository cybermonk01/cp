class Solution
{
public:
    vector<int> topoKahn(int n, unordered_map<int, list<int>> adj)
    {

        queue<int> q;
        vector<int> ans;

        unordered_map<int, int> indegree;

        for (auto it : adj)
        {
            int src = it.first;
            // har item ke liye indegree badha do
            for (auto nbr : it.second)
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

        while (!q.empty())
        {

            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto nbr : adj[front])
            {
                // hatane ke baad indegree kam ho jauyegi
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        if (ans.size() == n)
        {
            return ans;
        }
        else
        {
            return {};
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        unordered_map<int, list<int>> adj;
        for (auto task : prerequisites)
        {
            int u = task[0];
            int v = task[1];

            adj[v].push_back(u);
        }

        vector<int> ans = topoKahn(numCourses, adj);

        return ans;
    }
};

void topoKahn()
{

    queue<int> q;

    vector<int> ans;
    unordered_map<int, int> indegree;

    for (auto i : adj)
    {
        int src = i.first;

        for (auto pair :)
    }
}