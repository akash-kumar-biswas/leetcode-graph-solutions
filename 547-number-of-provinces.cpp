class Solution
{
public:
    void bfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, int u)
    {
        queue<int> q;
        q.push(u);
        vis[u] = true;
        while (!q.empty())
        {
            u = q.front();
            for (auto neigh : adj[u])
            {
                if (!vis[neigh])
                {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
            q.pop();
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_map<int, vector<int>> adj;
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && isConnected[i][j])
                {
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        vector<bool> vis(n + 1, false);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                bfs(adj, vis, i);
                cnt++;
            }
        }
        return cnt;
    }
};