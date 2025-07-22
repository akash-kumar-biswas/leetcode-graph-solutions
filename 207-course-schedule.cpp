class Solution
{
public:
    bool isCycleDfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, vector<bool> &inRecursion, int u)
    {
        vis[u] = true;
        inRecursion[u] = true;

        for (auto neigh : adj[u])
        {
            if (vis[neigh] && inRecursion[neigh])
                return true;
            if (!vis[neigh] && isCycleDfs(adj, vis, inRecursion, neigh))
                return true;
        }
        inRecursion[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        for (auto vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
            inDegree[vec[0]]++;
        }
        vector<bool> vis(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i] && isCycleDfs(adj, vis, inRecursion, i))
                return false;
        }

        return true;
    }
};