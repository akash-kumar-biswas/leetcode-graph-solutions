class Solution
{
public:
    int extraEdge = 0, dis_component = 0;

    void bfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, int u)
    {
        vis[u] = true;
        queue<pair<int, int>> q;
        q.push({u, -1});

        while (!q.empty())
        {
            u = q.front().first;
            int parent = q.front().second;

            for (auto neigh : adj[u])
            {
                if (vis[neigh] && neigh != parent)
                {
                    extraEdge++;
                }
                if (!vis[neigh])
                {
                    vis[neigh] = true;
                    q.push({neigh, u});
                }
            }
            q.pop();
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, vector<int>> adj;

        for (auto edge : connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bfs(adj, vis, i);
                dis_component++;
            }
        }
        extraEdge /= 2;
        return (extraEdge >= dis_component - 1) ? dis_component - 1 : -1;
    }
};