class Solution
{
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, int u, int &cnt)
    {
        vis[u] = true;
        cnt++;
        for (auto neigh : adj[u])
        {
            if (!vis[neigh])
            {
                dfs(adj, vis, neigh, cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<long long> comp_size;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int cnt = 0;
                dfs(adj, vis, i, cnt);
                comp_size.push_back(cnt);
            }
        }

        long long ans = 0;

        if (comp_size.size() == 1)
            return 0;

        int included_nodes = 0;

        for (auto it : comp_size)
        {
            ans += it * (n - included_nodes - it);
            included_nodes += it;
        }
        return ans;
    }
};