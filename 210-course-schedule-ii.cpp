class Solution
{
public:
    bool isCyclicDfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &vis, vector<bool> &inRecursion)
    {
        vis[u] = true;
        inRecursion[u] = true;

        for (auto neigh : adj[u])
        {
            if (vis[neigh] && inRecursion[neigh])
                return true;
            if (!vis[neigh] && isCyclicDfs(adj, neigh, vis, inRecursion))
                return true;
        }
        inRecursion[u] = false;
        return false;
    }

    void topoSortDfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, stack<int> &stk, int u)
    {
        vis[u] = true;

        for (auto neigh : adj[u])
        {
            if (!vis[neigh])
                topoSortDfs(adj, vis, stk, neigh);
        }
        stk.push(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<bool> inRecursion(numCourses, false);
        vector<bool> vis(numCourses, false);

        for (auto vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i] && isCyclicDfs(adj, i, vis, inRecursion))
                return {};
        }
        fill(vis.begin(), vis.end(), false);
        stack<int> stk;
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
                topoSortDfs(adj, vis, stk, i);
        }

        vector<int> ans;
        while (!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};